# coding: utf-8

"""
    Simple API

    A simple API to demonstrate OpenAPI to C++ stub generation.

    The version of the OpenAPI document: 1.0.0
    Generated by OpenAPI Generator (https://openapi-generator.tech)

    Do not edit the class manually.
"""  # noqa: E501


import unittest

from openapi_client.models.item_key import ItemKey

class TestItemKey(unittest.TestCase):
    """ItemKey unit test stubs"""

    def setUp(self):
        pass

    def tearDown(self):
        pass

    def make_instance(self, include_optional) -> ItemKey:
        """Test ItemKey
            include_optional is a boolean, when False only required
            params are included, when True both required and
            optional params are included """
        # uncomment below to create an instance of `ItemKey`
        """
        model = ItemKey()
        if include_optional:
            return ItemKey(
                tag_uuid = '',
                elem_uuid = '',
                owner_uuid = '',
                kind = 'ucat',
                seq_no = 56
            )
        else:
            return ItemKey(
                tag_uuid = '',
                owner_uuid = '',
                kind = 'ucat',
                seq_no = 56,
        )
        """

    def testItemKey(self):
        """Test ItemKey"""
        # inst_req_only = self.make_instance(include_optional=False)
        # inst_req_and_optional = self.make_instance(include_optional=True)

if __name__ == '__main__':
    unittest.main()
