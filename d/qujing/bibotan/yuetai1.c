#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "��̨С��");
  set ("long", @LONG

һ����ʯ�̳ɵ�С·ͨ��̶�����С���ϵ���ʯ�ڳ��˲�ͬͼ
������԰�£����¡�����һ·��ȥ�����Ǹ��ָ�����������С��
����ɨ�ĺܸɾ�����ͨ�������������ס����
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/changtui" : 1,
]));
//  set("outdoors", "xy23");
  

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"yuetai2",
  "west" : __DIR__"yuemen",
]));
//      
        set("water", 1);
//  
  setup();
}

