// /u/beyond/mr/yanziwu.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",WHT"������"NOR);
         set ("long",@long
��������Ļ��������֮��, Ļ������Ϧ�մ�����ĺ���, �����ռ�ʽ΢, 
�������ȴһ��һ����⸴���ࡣ���书�������Ա�֮��, ��ʩ����, �˵�
ʮ��������
long);
         set("exits",([
"north" : __DIR__"midaocao",
"south" : __DIR__"xiaojing1-2",
"west" : __DIR__"houyuan1",
             "east" : __DIR__"wuchang",
]));
set("roomif","$botten#��������|��������|�������|�Ͻ���Ʒ|��ȡ����|ȡ������:job|quest|ask shi about teamjob|give <��Ʒ> to shi|ask shi about gongxian|give 20 silver to shi$#");
set("objects",([
	"quest/menpaijob/mr/murong-fu" :1,
	"/d/biwu/champion_mr":1,
	"/d/mr/npc/puren":2,
	"/d/mr/npc/binu":2,
	"/quest/menpai/mr/shi":1,
]));
"/clone/board/murong_b.c"->foo();
         setup();
         replace_program(ROOM);
}