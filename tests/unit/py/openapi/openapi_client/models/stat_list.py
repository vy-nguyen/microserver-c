# coding: utf-8

"""
    Simple API

    A simple API to demonstrate OpenAPI to C++ stub generation.

    The version of the OpenAPI document: 1.0.0
    Generated by OpenAPI Generator (https://openapi-generator.tech)

    Do not edit the class manually.
"""  # noqa: E501


from __future__ import annotations
import pprint
import re  # noqa: F401
import json

from pydantic import BaseModel, ConfigDict
from typing import Any, ClassVar, Dict, List
from openapi_client.models.list_common import ListCommon
from openapi_client.models.stats import Stats
from typing import Optional, Set
from typing_extensions import Self

class StatList(BaseModel):
    """
    StatList
    """ # noqa: E501
    page: ListCommon
    list: List[Stats]
    __properties: ClassVar[List[str]] = ["page", "list"]

    model_config = ConfigDict(
        populate_by_name=True,
        validate_assignment=True,
        protected_namespaces=(),
    )


    def to_str(self) -> str:
        """Returns the string representation of the model using alias"""
        return pprint.pformat(self.model_dump(by_alias=True))

    def to_json(self) -> str:
        """Returns the JSON representation of the model using alias"""
        # TODO: pydantic v2: use .model_dump_json(by_alias=True, exclude_unset=True) instead
        return json.dumps(self.to_dict())

    @classmethod
    def from_json(cls, json_str: str) -> Optional[Self]:
        """Create an instance of StatList from a JSON string"""
        return cls.from_dict(json.loads(json_str))

    def to_dict(self) -> Dict[str, Any]:
        """Return the dictionary representation of the model using alias.

        This has the following differences from calling pydantic's
        `self.model_dump(by_alias=True)`:

        * `None` is only added to the output dict for nullable fields that
          were set at model initialization. Other fields with value `None`
          are ignored.
        """
        excluded_fields: Set[str] = set([
        ])

        _dict = self.model_dump(
            by_alias=True,
            exclude=excluded_fields,
            exclude_none=True,
        )
        # override the default output from pydantic by calling `to_dict()` of page
        if self.page:
            _dict['page'] = self.page.to_dict()
        # override the default output from pydantic by calling `to_dict()` of each item in list (list)
        _items = []
        if self.list:
            for _item_list in self.list:
                if _item_list:
                    _items.append(_item_list.to_dict())
            _dict['list'] = _items
        return _dict

    @classmethod
    def from_dict(cls, obj: Optional[Dict[str, Any]]) -> Optional[Self]:
        """Create an instance of StatList from a dict"""
        if obj is None:
            return None

        if not isinstance(obj, dict):
            return cls.model_validate(obj)

        _obj = cls.model_validate({
            "page": ListCommon.from_dict(obj["page"]) if obj.get("page") is not None else None,
            "list": [Stats.from_dict(_item) for _item in obj["list"]] if obj.get("list") is not None else None
        })
        return _obj

