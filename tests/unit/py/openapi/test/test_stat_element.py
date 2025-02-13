# coding: utf-8

"""
    Simple API

    A simple API to demonstrate OpenAPI to C++ stub generation.

    The version of the OpenAPI document: 1.0.0
    Generated by OpenAPI Generator (https://openapi-generator.tech)

    Do not edit the class manually.
"""  # noqa: E501


import unittest

from openapi_client.models.stat_element import StatElement

class TestStatElement(unittest.TestCase):
    """StatElement unit test stubs"""

    def setUp(self):
        pass

    def tearDown(self):
        pass

    def make_instance(self, include_optional) -> StatElement:
        """Test StatElement
            include_optional is a boolean, when False only required
            params are included, when True both required and
            optional params are included """
        # uncomment below to create an instance of `StatElement`
        """
        model = StatElement()
        if include_optional:
            return StatElement(
                item_id = openapi_client.models.item_id.ItemId(
                    uuid = '', 
                    kind = 'ucat', 
                    seq_no = 56, ),
                peer_id = openapi_client.models.item_id.ItemId(
                    uuid = '', 
                    kind = 'ucat', 
                    seq_no = 56, ),
                counter = openapi_client.models.counter.Counter(
                    name = '', 
                    value = 56, )
            )
        else:
            return StatElement(
                item_id = openapi_client.models.item_id.ItemId(
                    uuid = '', 
                    kind = 'ucat', 
                    seq_no = 56, ),
        )
        """

    def testStatElement(self):
        """Test StatElement"""
        # inst_req_only = self.make_instance(include_optional=False)
        # inst_req_and_optional = self.make_instance(include_optional=True)

if __name__ == '__main__':
    unittest.main()
