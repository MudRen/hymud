#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "�ӻ���");
  set ("long", @LONG
�������ӻ��̣����ų����Ļ����ϰ������������
��Ҫ�Ķ������ϰ��Ǹ����ֵ������ˣ�����һ�߾�����к���
���ˣ��������Ҫʲô�Ļ����Կ���������ָ�� list����
LONG);
  set("exits", ([ /* sizeof() == 2 */

"north" : __DIR__"new1",

]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yang" : 1,
 
]));

set("roomif","$botten#�鿴|����:list|buy <��Ʒѡȡ>$#");

  set("no_beg", 1);
  set("pingan",1);
  set("no_fight", 1);
  set("chatroom",1);
  setup();
  replace_program(ROOM);
}