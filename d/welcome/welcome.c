// /d/welcome/welcome.c
// ����II
// ����(lywin) 2000/6/4

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "����֮��");
  set ("long", @LONG
�����ǹŴ�������ģ�һ���ܿ����Ĺ㳡������������ʯ���档��
��һ�ô���(tree)�̸���ڣ��Ѿ����������������Ŷ��������ˣ���
���Ǵ�˵�е�����֮��������˵�����������������������ɫ������Ȼ
֮�档����վ��һ�����ߣ������ĵظ��������֡�
==== �������Ҫ����������ָ�� ask lao about here ====
==== �������Ҫ�޸���������   help cgift ====
LONG);

  set("exits", ([ /* sizeof() == 2 */
"south" : __DIR__"dangpu",	
"north" : __DIR__"qianzhuang",	
"west" : __DIR__"ck",	
"east" : __DIR__"new1",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"jing" : 1,
 //"/clone/gift/newbieliwu" : 1,
]));
  set("outdoors","welcome");
//  set("sleep_room", 1);
  set("roomif","$botten#��������|�������|���ְ���|����:ask lao about job|ask lao about ok|ask lao about here|ask lao about ����$#");
  set("no_beg", 1);
  set("valid_startroom", "1");
  set("pingan", 1);
  set("no_fight", 1);
set("chatroom",1);
  setup();
  replace_program(ROOM);
	"/clone/board/newbie_b"->foo();
}
void init()
{
	object me;
me=this_player();
if( me->query_temp("netdead")) 
"/cmds/usr/quitgame"->main(me);
	return;
}
         