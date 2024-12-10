#pragma once

#include <functional>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

namespace seal {

class ProgOpts;

struct popt_arg_t
{
  public:
    friend class ProgOpts;
    popt_arg_t(const char *key, const char *sopt, const char *lopt,
            const char *arg_desc, const char *desc,
            bool required = true, bool flag = false) :
        m_key(key),
        m_sopt(sopt),
        m_lopt(lopt),
        m_arg_desc(arg_desc),
        m_desc(desc),
        m_required(required),
        m_flag(flag),
        m_flag_on(false),
        m_action(nullptr) {}

    long to_long() const
    {
        try {
            if (m_required && !m_flag) {
                return std::stol(m_value);
            }
        } catch(...) {
        }
        return 0;
    }

    void print(std::ostringstream& os) const
    {
        os << (m_required ? "<" : "[");
        os << m_sopt << " | " << m_lopt;
        if (!m_flag && m_arg_desc != "") {
            os << " " << m_arg_desc;
        }
        os << (m_required ? ">" : "]") << " - " << m_desc << "\n";
    }

    const std::string& value() const {
        return m_value;
    }

    void set_flag() {
        m_flag_on = true;
    }

    void set_value(const std::string_view& val) {
        m_value = std::string(val);
        m_flag_on = true;
    }

  private:
    std::string_view m_key;
    std::string_view m_sopt;
    std::string_view m_lopt;
    std::string_view m_arg_desc;
    std::string_view m_desc;
    std::string      m_value;
    bool             m_required;   // true, must have this argument.
    bool             m_flag;       // true, flag arg not expecting value.
    bool             m_flag_on;
    std::function<void(const popt_arg_t&)> m_action;
};

class ProgOpts
{
  public:
    ProgOpts(int argc, char *argv[]) : m_empty("", "", "", "na", "na")
    {
        for (int i = 0; i < argc; i++) {
            m_argv.emplace_back(argv[i]);
        }
    }

    void add_option(const char *key, const char *sopt, const char *lopt,
            const char *arg_desc, const char *desc,
            bool required = false, bool flag = false) {
        m_opts.emplace(key,
                popt_arg_t{key, sopt, lopt, arg_desc, desc, required, flag});
    }

    void add_action(std::string_view key,
            std::function<void(const popt_arg_t&)> action);
    void bind_help(std::string_view key);

    popt_arg_t& get_option(std::string_view key);
    bool valid(const popt_arg_t& key) const;

    bool valid_opt(std::string_view key) {
        return valid(get_option(key));
    }

    void parse();
    void help(std::ostringstream& os) const;

  private:
    popt_arg_t                                       m_empty;
    std::vector<std::string_view>                    m_argv;
    std::unordered_map<std::string_view, popt_arg_t> m_opts;

    void print_help(const popt_arg_t&) const;
    void process_opt(std::vector<std::string_view>::iterator&,
            std::string_view key, const std::string_view *value);
};

}
