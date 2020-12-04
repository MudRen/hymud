// Room: /d/fengtian/jiulou.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "������¥");
	set("long", @LONG
������¥��ʢ������һ������Ҳ�����ľ�¥������ս�Һ�
�٣���Ȼ��ҵ�ͷ��������¥ѡ�����ֽֿ���Ҳ����Ϊ����Խ
��Խ�����ˡ�
LONG
	);
	set("night_long", @LONG
������¥��ʢ������һ������Ҳ�����ľ�¥�������Ѿ���
���ˣ����õ�û����ɵ�ſ�ڹ�̨�ϡ�
LONG
        );

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"ll4",
  "west" : __DIR__"jiulou2",
]));

	
	set("valid_startroom", 1);

	set("objects",([
	__DIR__"npc/paotang" : 1,
]));

	setup();
	//load_board("board_fengtian");
}

void open_close_door(string msg,object user)
{
        object ob = present("pao tang",this_object());

        if(!msg || !user)
                return;
        if( msg == "begin_day")
        {
                if(ob)
                        tell_object(user,CYN"��¥����Цӯӯ�Ķ���˵������¥��ʼӪҵ�ˣ���"+
                        RANK_D->query_respect(user)+"�����⡣\n"NOR);
                else
                        tell_object(user,CYN ""+query("short")+"��ʼӪҵ�ˡ�\n"NOR);
                return;
        }

        else if( msg == "begin_night")
        {
                if(ob)
                        tell_object(user,CYN"��¥����˵������λ"+
                        RANK_D->query_respect(user)+"�Բ���С�Ŵ����ˣ��������������ɡ�\n"NOR);
                else
                        tell_object(user,CYN ""+query("short")+"�����ˡ�\n"NOR);
                return;
        }
}
