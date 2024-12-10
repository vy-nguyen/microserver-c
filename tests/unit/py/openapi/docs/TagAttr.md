# TagAttr


## Properties

Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**tag_uuid_key** | **str** |  | 
**tag_rank** | **int** |  | [optional] [default to 0]
**tag_score** | **int** |  | [optional] [default to 0]
**up_vote_count** | **int** |  | [optional] [default to 0]
**down_vote_count** | **int** |  | [optional] [default to 0]
**shared_count** | **int** |  | [optional] 
**read_count** | **int** |  | [optional] 
**show_count** | **int** |  | [optional] 
**comment_count** | **int** |  | [optional] 
**follow_count** | **int** |  | [optional] 
**book_mark_count** | **int** |  | [optional] 
**blocked_count** | **int** |  | [optional] 

## Example

```python
from openapi_client.models.tag_attr import TagAttr

# TODO update the JSON string below
json = "{}"
# create an instance of TagAttr from a JSON string
tag_attr_instance = TagAttr.from_json(json)
# print the JSON string representation of the object
print(TagAttr.to_json())

# convert the object into a dict
tag_attr_dict = tag_attr_instance.to_dict()
# create an instance of TagAttr from a dict
tag_attr_from_dict = TagAttr.from_dict(tag_attr_dict)
```
[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


