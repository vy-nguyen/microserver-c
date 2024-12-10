# coding: utf-8

"""
    Simple API

    A simple API to demonstrate OpenAPI to C++ stub generation.

    The version of the OpenAPI document: 1.0.0
    Generated by OpenAPI Generator (https://openapi-generator.tech)

    Do not edit the class manually.
"""  # noqa: E501


import unittest

from openapi_client.models.stat_list import StatList

class TestStatList(unittest.TestCase):
    """StatList unit test stubs"""

    def setUp(self):
        pass

    def tearDown(self):
        pass

    def make_instance(self, include_optional) -> StatList:
        """Test StatList
            include_optional is a boolean, when False only required
            params are included, when True both required and
            optional params are included """
        # uncomment below to create an instance of `StatList`
        """
        model = StatList()
        if include_optional:
            return StatList(
                page = openapi_client.models.list_common.ListCommon(
                    page_info = openapi_client.models.page_info.PageInfo(
                        total = 56, 
                        current = 56, 
                        seq_no = 56, 
                        item_count = 56, ), 
                    extras = [
                        openapi_client.models.item_id.ItemId(
                            uuid = '', 
                            kind = 'ucat', 
                            seq_no = 56, )
                        ], ),
                list = [
                    openapi_client.models.stats.Stats(
                        item_id = openapi_client.models.item_id.ItemId(
                            uuid = '', 
                            kind = 'ucat', 
                            seq_no = 56, ), 
                        likes = 56, 
                        bookmark = 56, 
                        shares = 56, 
                        extras = [
                            openapi_client.models.counter.Counter(
                                name = '', 
                                value = 56, )
                            ], )
                    ]
            )
        else:
            return StatList(
                page = openapi_client.models.list_common.ListCommon(
                    page_info = openapi_client.models.page_info.PageInfo(
                        total = 56, 
                        current = 56, 
                        seq_no = 56, 
                        item_count = 56, ), 
                    extras = [
                        openapi_client.models.item_id.ItemId(
                            uuid = '', 
                            kind = 'ucat', 
                            seq_no = 56, )
                        ], ),
                list = [
                    openapi_client.models.stats.Stats(
                        item_id = openapi_client.models.item_id.ItemId(
                            uuid = '', 
                            kind = 'ucat', 
                            seq_no = 56, ), 
                        likes = 56, 
                        bookmark = 56, 
                        shares = 56, 
                        extras = [
                            openapi_client.models.counter.Counter(
                                name = '', 
                                value = 56, )
                            ], )
                    ],
        )
        """

    def testStatList(self):
        """Test StatList"""
        # inst_req_only = self.make_instance(include_optional=False)
        # inst_req_and_optional = self.make_instance(include_optional=True)

if __name__ == '__main__':
    unittest.main()