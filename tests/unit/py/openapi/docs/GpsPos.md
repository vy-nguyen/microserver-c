# GpsPos


## Properties

Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**item_id** | [**ItemId**](ItemId.md) |  | 
**lng** | **float** |  | 
**lat** | **float** |  | 

## Example

```python
from openapi_client.models.gps_pos import GpsPos

# TODO update the JSON string below
json = "{}"
# create an instance of GpsPos from a JSON string
gps_pos_instance = GpsPos.from_json(json)
# print the JSON string representation of the object
print(GpsPos.to_json())

# convert the object into a dict
gps_pos_dict = gps_pos_instance.to_dict()
# create an instance of GpsPos from a dict
gps_pos_from_dict = GpsPos.from_dict(gps_pos_dict)
```
[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


