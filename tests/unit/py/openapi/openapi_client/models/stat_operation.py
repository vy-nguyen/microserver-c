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

from pydantic import BaseModel, ConfigDict, Field
from typing import Any, ClassVar, Dict, List
from openapi_client.models.item_key import ItemKey
from openapi_client.models.signature import Signature
from openapi_client.models.stat_element import StatElement
from typing import Optional, Set
from typing_extensions import Self

class StatOperation(BaseModel):
    """
    StatOperation
    """ # noqa: E501
    item_key: ItemKey = Field(alias="itemKey")
    signature: Signature
    values: List[StatElement]
    __properties: ClassVar[List[str]] = ["itemKey", "signature", "values"]

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
        """Create an instance of StatOperation from a JSON string"""
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
        # override the default output from pydantic by calling `to_dict()` of item_key
        if self.item_key:
            _dict['itemKey'] = self.item_key.to_dict()
        # override the default output from pydantic by calling `to_dict()` of signature
        if self.signature:
            _dict['signature'] = self.signature.to_dict()
        # override the default output from pydantic by calling `to_dict()` of each item in values (list)
        _items = []
        if self.values:
            for _item_values in self.values:
                if _item_values:
                    _items.append(_item_values.to_dict())
            _dict['values'] = _items
        return _dict

    @classmethod
    def from_dict(cls, obj: Optional[Dict[str, Any]]) -> Optional[Self]:
        """Create an instance of StatOperation from a dict"""
        if obj is None:
            return None

        if not isinstance(obj, dict):
            return cls.model_validate(obj)

        _obj = cls.model_validate({
            "itemKey": ItemKey.from_dict(obj["itemKey"]) if obj.get("itemKey") is not None else None,
            "signature": Signature.from_dict(obj["signature"]) if obj.get("signature") is not None else None,
            "values": [StatElement.from_dict(_item) for _item in obj["values"]] if obj.get("values") is not None else None
        })
        return _obj


