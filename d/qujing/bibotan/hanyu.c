#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

���������ú�����ɣ�����ɫ�ĺ����ȡ���Ǳ�ڤѩɽ֮�У���
��͸������ӫ�⣬��������������͸�ǵĺ��������е���з����
�º��䣬���������������壬�����γ������ĶԱȡ�
LONG);


	set("cold", 1);
//  set("outdoors", "xy23");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"shuijg",
]));
//      
        set("water", 1);
//  
  setup();
}
