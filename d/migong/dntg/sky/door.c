inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "��������");
  set ("long", @LONG
        
     ��������������ɽ֮�ۣ�����;����������ȣ�Ҳ��
������κ�ΰ��ɽ���ƾɣ��������ʧ�ޡ�
LONG);

  set("outdoors", __DIR__"");
  set("magicroom",1);set("exits", ([ /* sizeof() == 3 */
  "enter" : __DIR__"xiaoyuan",
  "south" : __DIR__"shanlu4",

]));

  create_door("enter", "����", "out", DOOR_CLOSED);
set("valid_startroom", 1);
setup();

}
