//writen by lnwm
//gudi.c

inherit ROOM;
void create()
{
    set("short", "�ȵ�");
    set("long", @LONG
����ǰ��Ȼһ����,Ⱥɽ����������Ժ�,ɽ�ƶ�Ȼһ��,һ������Ⱥɽ֮��
��ɽ���������.���з�������.һ��СϪ�����ӱ���һ��ɽ��������,Ȼ���ڹ���
���˼������غ����Ͼ�ֱ��ȥ��.��������ߴ�Խ�ȵ�����. ���ܿ���ԶԶ�ĵ���
���и������Ƶ�ѩ�崣��.���������ظ�ԭ��Ȼ������.
LONG
        );
    set("exits", ([ 
	    "east"      :       __DIR__ "outshangu", 
    ]));
    set("item_desc", ([
        "ɽ��"     :	 "���������ڵ�ɽ�꣬��Χ�Ĳ���Щ�������ƺ����˾������롣\n",
        ]) );
    set("outdoors","lnwm");
    setup();
}

void init()
{
	add_action("do_enter","enter");
	add_action("do_enter","go");
}

int do_enter(string arg)
{
    object me;
    if(!arg || arg=="")
    {
        write("��Ҫȥ�ģ�\n");
        return 1;
    }
    if( arg == "shanao" || arg == "ɽ��" )
    {
        me = this_player();
		if((int) me->query("combat_exp") >= 100000 )
    	{
		message_vision("$N��ɽ����ȥ��\n", me);
		me->move(__DIR__ "shanpo");
		return 1;
		}
		else
        {
			tell_object(me,"���Ȼ��Щ���£���̧��Ľ������˻�ȥ��\n");
        	return 1;
		}
    }
}    