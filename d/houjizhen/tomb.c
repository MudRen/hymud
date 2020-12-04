// tomb.c
// by dicky

#include <ansi.h>
inherit ROOM;
string look_shibei();
int do_pull(string arg);
void close_door();

void create()
{
	set("short","��Ĺ");
	set("long", @LONG
����һ�����ڸ�����ߴ���һ����أ����ϲ��˼����㣬����ȼ�š�
�������˾������⡣��������һ����ʯ�����Ա߻���һ��������������
(huan)�������ܴ󣬳���������Զ���������󹷷�������ʲôҲ����
����
LONG);

        set("outdoors", "houjizhen");

	set("item_desc",([
//	"shibei" : (: look_shibei :),
	"huan" : "����һ������������ȥʮ�ֹ⻬��\n",
	]));
	set("exits",([
	"southeast" : __DIR__"shangang",
	"northwest" : __DIR__"shigang",
	]));

	setup();
}




void init()
{
	add_action("do_pull", "pull");
}

string look_shibei()
{
	return
	"\n"
	"   ������������������������������? \n"
	"   ������                  ������   \n"
	"   ������     ��������     ������   \n"
	"   ������     ����ؤ��     ������   \n"
	"   ������                  ������   \n"
        "   ������������������������������   \n";
}
int do_pull(string arg)
{
//	string dir;
        object room;

	if( !arg || arg!="huan" ) return 0;
	message("vision","Ĺ����Ȼ������������������һ�໺���ƿ���"
	                "����¶��һ���ڶ�������ڡ�\n", this_object() );
	set("exits/down", __DIR__"tomb1");
	if( room = load_object(__DIR__"tomb") ) {
 		 room->set("exits/up", __FILE__);

	} 
	remove_call_out("close_door");
	call_out("close_door", 3);
        return 1;
}

void close_door()
{
	object room;

        if( !query("exits/down") ) return;
        message("vision","Ĺ����Ȼ�����������������������ƻ�ԭ����"
                "�����µĶ��ڸ�ס�ˡ�\n", this_object() );
        if( room = load_object(__DIR__"tomb1") ) {
                room->delete("exits/up");
                message("vision", "ͷ���ϵ�Ĺ����Ȼ����������������"
                        "ǽ�ϵ�ʯ���ֻ��������˻�ȥ��������ʧ�ˡ�\n", 
room );
        }
        delete("exits/down");
}
