#include <iostream>
#include <sstream>
#include <unordered_map>
#include <util/prog_opts.h>

namespace seal {

bool ProgOpts::valid(const popt_arg_t& opt) const {
    return &opt != &m_empty && (opt.m_flag || (opt.m_required && !opt.m_value.empty()));
}

popt_arg_t& ProgOpts::get_option(std::string_view opt)
{
    auto it = m_opts.find(opt);
    if (it != m_opts.end()) {
        return it->second;
    }
    return m_empty;
}

void ProgOpts::help(std::ostringstream& os) const
{
    os << "Server command line options\n";
    for (const auto& it : m_opts) {
        os << "\t";
        it.second.print(os);
    }
}

void ProgOpts::add_action(std::string_view key, std::function<void()> action)
{
    auto opt = m_opts.find(key);
    if (opt != m_opts.end()) {
        opt->second.m_action = action;
    }
}

void ProgOpts::print_help() const 
{
    auto os = std::ostringstream();
    help(os);
    std::cout << os.str() << std::endl;
}

void ProgOpts::bind_help(std::string_view key) {
    add_action(key, std::bind(&ProgOpts::print_help, this));
}

void ProgOpts::parse()
{
    auto map = std::unordered_map<std::string_view, std::string_view>();
    for (const auto& it : m_opts) {
        auto key = it.second.m_key;
        map.emplace(it.second.m_sopt, key);
        map.emplace(it.second.m_lopt, key);
    }
    for (auto it = m_argv.begin(); it != m_argv.end(); ++it) {
        auto val = it->data();
        if (val[0] == '-') {
            if (val[1] == '-') {
                // Handle long option.
                auto pos = it->find("-");
                if (pos != std::string::npos) {
                    auto opt = it->substr(0, pos);
                    auto value = it->substr(pos + 1);
                    const auto key = map.find(opt);
                    if (key != map.end()) {
                        process_opt(it, key->second, &value);
                    }
                } else {
                    const auto key = map.find(*it);
                    if (key != map.end()) {
                        process_opt(it, key->second, nullptr);
                    }
                }
            } else {
                // Handle short option.
                const auto key = map.find(*it);
                if (key != map.end()) {
                    process_opt(it, key->second, nullptr);
                }
            }
        }
    }
    auto error = false;
    for (const auto& it : m_opts) {
        auto& opt = it.second;
        if (opt.m_key == "") {
            continue;
        }
        if (opt.m_required && opt.m_flag_on == false) {
            error = true;
            std::cout << "Expect argument after " << opt.m_sopt << "\n";
        }
        auto action = opt.m_action;
        if (opt.m_flag_on && action != nullptr) {
            action();
        }
    }
    if (error) {
        print_help();
    }
}

void ProgOpts::process_opt(std::vector<std::string_view>::iterator& it,
        std::string_view key, const std::string_view *value)
{
    auto& opt = get_option(key);
    if (valid(opt)) {
        if (opt.m_flag) {
            opt.set_flag();
        } else if (value != nullptr) {
            opt.set_value(*value);
        } else {
            it = std::next(it);
            if (it != m_argv.end()) {
                opt.set_value(*it);
            }
        }
    }
}

}
