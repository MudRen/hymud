#include <room.h>
inherit ROOM;


void create ()
{
  set ("short", "��¥̨");
  set ("long", @LONG

���˹���һС̨��Զ���ɾ���������������ϼ������ǧ������
�̡�Զ�ϳ��ű����ɣ��칬����ӳ�ƹ⡣�����������������ɾ���
�����˼�����ࡣ
LONG);

  set("magicroom",1);set("exits", ([ /* sizeof() == 1 */
    "down": __DIR__"yunlou",
  ]));
  set("objects", ([ /* sizeof() == 3 */
   __DIR__"npc/litianwang":1,
]));

set("outdoors", "dntg");
  setup();
}


