# coding: utf-8

# flake8: noqa

"""
    Simple API

    A simple API to demonstrate OpenAPI to C++ stub generation.

    The version of the OpenAPI document: 1.0.0
    Generated by OpenAPI Generator (https://openapi-generator.tech)

    Do not edit the class manually.
"""  # noqa: E501


__version__ = "1.0.0"

# import apis into sdk package
from openapi_client.api.default_api import DefaultApi

# import ApiClient
from openapi_client.api_response import ApiResponse
from openapi_client.api_client import ApiClient
from openapi_client.configuration import Configuration
from openapi_client.exceptions import OpenApiException
from openapi_client.exceptions import ApiTypeError
from openapi_client.exceptions import ApiValueError
from openapi_client.exceptions import ApiKeyError
from openapi_client.exceptions import ApiAttributeError
from openapi_client.exceptions import ApiException

# import models into sdk package
from openapi_client.models.counter import Counter
from openapi_client.models.gps_pos import GpsPos
from openapi_client.models.id_kind import IdKind
from openapi_client.models.item_id import ItemId
from openapi_client.models.item_id_array import ItemIdArray
from openapi_client.models.item_id_list import ItemIdList
from openapi_client.models.item_key import ItemKey
from openapi_client.models.key_val import KeyVal
from openapi_client.models.list_common import ListCommon
from openapi_client.models.page_info import PageInfo
from openapi_client.models.signature import Signature
from openapi_client.models.stat_element import StatElement
from openapi_client.models.stat_list import StatList
from openapi_client.models.stat_operation import StatOperation
from openapi_client.models.stats import Stats
from openapi_client.models.tag_attr import TagAttr
from openapi_client.models.test_get_get200_response import TestGetGet200Response
