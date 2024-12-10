# coding: utf-8

"""
    Simple API

    A simple API to demonstrate OpenAPI to C++ stub generation.

    The version of the OpenAPI document: 1.0.0
    Generated by OpenAPI Generator (https://openapi-generator.tech)

    Do not edit the class manually.
"""  # noqa: E501


import unittest

from openapi_client.models.item_id_list import ItemIdList

class TestItemIdList(unittest.TestCase):
    """ItemIdList unit test stubs"""

    def setUp(self):
        pass

    def tearDown(self):
        pass

    def make_instance(self, include_optional) -> ItemIdList:
        """Test ItemIdList
            include_optional is a boolean, when False only required
            params are included, when True both required and
            optional params are included """
        # uncomment below to create an instance of `ItemIdList`
        """
        model = ItemIdList()
        if include_optional:
            return ItemIdList(
                op = '',
                reg_code = '',
                parent_uuid = '',
                op_uuid = '',
                op_kind = '',
                op_seq = 56,
                op_page = 56,
                records = [
                    openapi_client.models.item_id.ItemId(
                        uuid = '', 
                        kind = 'ucat', 
                        seq_no = 56, )
                    ],
                filter = [
                    openapi_client.models.item_id.ItemId(
                        uuid = '', 
                        kind = 'ucat', 
                        seq_no = 56, )
                    ]
            )
        else:
            return ItemIdList(
        )
        """

    def testItemIdList(self):
        """Test ItemIdList"""
        # inst_req_only = self.make_instance(include_optional=False)
        # inst_req_and_optional = self.make_instance(include_optional=True)

if __name__ == '__main__':
    unittest.main()