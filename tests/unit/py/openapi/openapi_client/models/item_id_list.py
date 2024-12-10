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

from pydantic import BaseModel, ConfigDict, Field, StrictInt, StrictStr
from typing import Any, ClassVar, Dict, List, Optional
from openapi_client.models.item_id import ItemId
from typing import Optional, Set
from typing_extensions import Self

class ItemIdList(BaseModel):
    """
    ItemIdList
    """ # noqa: E501
    op: Optional[StrictStr] = None
    reg_code: Optional[StrictStr] = Field(default=None, alias="regCode")
    parent_uuid: Optional[StrictStr] = Field(default=None, alias="parentUuid")
    op_uuid: Optional[StrictStr] = Field(default=None, alias="opUuid")
    op_kind: Optional[StrictStr] = Field(default=None, alias="opKind")
    op_seq: Optional[StrictInt] = Field(default=0, alias="opSeq")
    op_page: Optional[StrictInt] = Field(default=0, alias="opPage")
    records: Optional[List[ItemId]] = None
    filter: Optional[List[ItemId]] = None
    __properties: ClassVar[List[str]] = ["op", "regCode", "parentUuid", "opUuid", "opKind", "opSeq", "opPage", "records", "filter"]

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
        """Create an instance of ItemIdList from a JSON string"""
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
        # override the default output from pydantic by calling `to_dict()` of each item in records (list)
        _items = []
        if self.records:
            for _item_records in self.records:
                if _item_records:
                    _items.append(_item_records.to_dict())
            _dict['records'] = _items
        # override the default output from pydantic by calling `to_dict()` of each item in filter (list)
        _items = []
        if self.filter:
            for _item_filter in self.filter:
                if _item_filter:
                    _items.append(_item_filter.to_dict())
            _dict['filter'] = _items
        return _dict

    @classmethod
    def from_dict(cls, obj: Optional[Dict[str, Any]]) -> Optional[Self]:
        """Create an instance of ItemIdList from a dict"""
        if obj is None:
            return None

        if not isinstance(obj, dict):
            return cls.model_validate(obj)

        _obj = cls.model_validate({
            "op": obj.get("op"),
            "regCode": obj.get("regCode"),
            "parentUuid": obj.get("parentUuid"),
            "opUuid": obj.get("opUuid"),
            "opKind": obj.get("opKind"),
            "opSeq": obj.get("opSeq") if obj.get("opSeq") is not None else 0,
            "opPage": obj.get("opPage") if obj.get("opPage") is not None else 0,
            "records": [ItemId.from_dict(_item) for _item in obj["records"]] if obj.get("records") is not None else None,
            "filter": [ItemId.from_dict(_item) for _item in obj["filter"]] if obj.get("filter") is not None else None
        })
        return _obj


