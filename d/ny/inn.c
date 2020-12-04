//inn.c
#include <room.h>

#include <ansi.h>
inherit ROOM;

string look_sign(object me);

void create()
{
	set("coor",({-20,4750,10}));
	set("short",CYN"��һ���ջ"NOR);
	set("long",
"��������վ����Զ�ϱߵ�һ��С��ջ���ҿ�ջ��С��ȴ�Ƿ�Բ��������ʢ����һ��\n"
"����ջ�����˾�˵��һλ�����ĺ������ˣ������ĸ�Ե���Ļ���Ҳ�����������������\n"
"������֮�⣬���Ը��ص����˶�ϲ���ۼ������ｻ����;�ϵļ��ţ���Ҳ���������������\n"
"�����Ȥ����Ϣ�������ſڵĵط���һ����ľ��ɵ�����(sign)����������һ����ľ��(doo\n"
"r)�����Ϸ���һ���ɫ�Ĺ��Σ�һ�����˸о������������ֺ���͵Ĺ�â��\n"
);

	// This enables players to save this room as their startroom.
	set("valid_startroom", 1);


	
	set("exits", ([
        	"east"      : __DIR__"square",
        	"up"        : __DIR__"inn_2f"
 ]) );

        set("objects", ([ /* sizeof() == 2 */
         __DIR__"npc/wt" : 1,
]));


	
	
	setup();

}

string look_sign(object me)
{
	if( wizardp(me) )
   return "����д������һ���ջ���Ա�һ��С�֣�ׯ˼���⡣\n";
	else
   return "����д������һ���ջ��\n";
}
