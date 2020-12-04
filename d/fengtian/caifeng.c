// Room: /d/fengtian/caifeng.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "�÷���");
	set("long", @LONG
����������ʢ�����ǵ�һ��÷��̣�������ϰ����������
�ɡ�Զ���������ű�����һ���ľ��(sign)��
LONG
	);

	set("night_long", @LONG
����������ʢ�����ǵ�һ��÷��̣�������ϰ����������
�ɡ�Զ�������������Ѿ������ˡ�
LONG
	);

	set("item_desc",([
		"sign" : "������۸�ʽ��Ů��װ��Ҳ������(ding)����\n",
	]));

	set("no_sleep_room",1);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"ll4",
]));
	set("objects",([
		__DIR__"npc/cloth_li" : 1,
]));

	setup();
}

void open_close_door(string msg,object user)
{
	object ob = present("boss zhang",this_object());

        if(!msg || !user)
                return;
	if( msg == "begin_day")
        {
                if(ob)
                        tell_object(user,CYN"����Цӯӯ�Ķ���˵������ʼӪҵ�ˣ���"+
                        RANK_D->query_respect(user)+"����㿴����\n"NOR);
                else
                        tell_object(user,CYN ""+query("short")+"��ʼӪҵ�ˡ�\n"NOR);
                return;
        }

	else if( msg == "begin_night")
        {
                if(ob)
                        tell_object(user,CYN"����˵������λ"+
                        RANK_D->query_respect(user)+"�Բ��𣬱ɵ�����ˣ��������������ɡ�\n"NOR);
                else
                        tell_object(user,CYN ""+query("short")+"�����ˡ�\n"NOR);
                return;
        }
}
