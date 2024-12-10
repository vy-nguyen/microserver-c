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
from typing import Optional, Set
from typing_extensions import Self

class TagAttr(BaseModel):
    """
    TagAttr
    """ # noqa: E501
    tag_uuid_key: StrictStr = Field(alias="tagUuidKey")
    tag_rank: Optional[StrictInt] = Field(default=0, alias="tagRank")
    tag_score: Optional[StrictInt] = Field(default=0, alias="tagScore")
    up_vote_count: Optional[StrictInt] = Field(default=0, alias="upVoteCount")
    down_vote_count: Optional[StrictInt] = Field(default=0, alias="downVoteCount")
    shared_count: Optional[StrictInt] = Field(default=None, alias="sharedCount")
    read_count: Optional[StrictInt] = Field(default=None, alias="readCount")
    show_count: Optional[StrictInt] = Field(default=None, alias="showCount")
    comment_count: Optional[StrictInt] = Field(default=None, alias="commentCount")
    follow_count: Optional[StrictInt] = Field(default=None, alias="followCount")
    book_mark_count: Optional[StrictInt] = Field(default=None, alias="bookMarkCount")
    blocked_count: Optional[StrictInt] = Field(default=None, alias="blockedCount")
    __properties: ClassVar[List[str]] = ["tagUuidKey", "tagRank", "tagScore", "upVoteCount", "downVoteCount", "sharedCount", "readCount", "showCount", "commentCount", "followCount", "bookMarkCount", "blockedCount"]

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
        """Create an instance of TagAttr from a JSON string"""
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
        return _dict

    @classmethod
    def from_dict(cls, obj: Optional[Dict[str, Any]]) -> Optional[Self]:
        """Create an instance of TagAttr from a dict"""
        if obj is None:
            return None

        if not isinstance(obj, dict):
            return cls.model_validate(obj)

        _obj = cls.model_validate({
            "tagUuidKey": obj.get("tagUuidKey"),
            "tagRank": obj.get("tagRank") if obj.get("tagRank") is not None else 0,
            "tagScore": obj.get("tagScore") if obj.get("tagScore") is not None else 0,
            "upVoteCount": obj.get("upVoteCount") if obj.get("upVoteCount") is not None else 0,
            "downVoteCount": obj.get("downVoteCount") if obj.get("downVoteCount") is not None else 0,
            "sharedCount": obj.get("sharedCount"),
            "readCount": obj.get("readCount"),
            "showCount": obj.get("showCount"),
            "commentCount": obj.get("commentCount"),
            "followCount": obj.get("followCount"),
            "bookMarkCount": obj.get("bookMarkCount"),
            "blockedCount": obj.get("blockedCount")
        })
        return _obj

