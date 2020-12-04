// by dubei

#include <ansi.h>
#include <room.h>

inherit ROOM;

string jianzhong(object);

void create()
{
    set("short", BLU "ƽ̨"NOR);
    set("long", @LONG
ֻ�����ʯ�����һ����ء���ر���ɽ�ȣ�������������ʯ�Ͻ�
ڣ(jianzhong)��������֮�ԣ��������������С��ʯ�̣�
    ��ħ������ܼ��޵�����£������˹��
�����غ���Ⱥ�����֣��������������౯��
LONG
    );

    set("item_desc", ([
        "jianzhong" : (: jianzhong :),
    ]));

    set("outdoors", "xiangyang");
        set("no_clean_up", 1);

    setup();
}

string jianzhong(object me)
{
    object where = environment(me);
	if(where->query_temp("temp/ban")<1)
    {
        return  "������һ����������ǰ����߾����书��˵�����������ὣ������֮�ࡣ��\n";
    }

    return "�Ὺڣ��ʯ���¶���������������������ڵ�һ���ڶ����ѽ�֮\n"+
"�䣬����һ�鳤��ʯƬ����������ʯƬ�����һ�����ʯ֮�ϡ�\n"+
"ʯ�Ͽ��֣�\n\n"+
"        �� ��       �� ��       �� ��       �� �� ��\n"+
"        �� ��       �� ޱ       ʮ ��       �� ľ ʮ\n"+
"        ǰ ��       �� ��       �� ��       �� �� ��\n"+
"        �� ��       �� ��       ǰ ��       �� ʯ ��\n"+
"        ֮          ��          ��          �� ��\n"+
"        �� ��          ��       ֮ ��       ʤ �� ��\n"+
"        �� ��       �� ʮ       �� ��       �� Ϊ ��\n"+
"        ˷ ��       �� ��       �� ��       �� �� ��\n"+
"        Ⱥ ��       ֮ ǰ       �� ��       ֮    ��\n"+
"        ��          �� ��       ��          �� ��\n"+
"        ��          �� ��                      ��\n"+
"        ��                                     ��\n"+
"                                               ��\n";

}


void init()
{
        add_action("do_move", "move");
        add_action("do_jump", "jump");
}


int do_move(string arg)
{
	int i;
    object me = this_player(), ob_jian, ob_xtj,who,where = environment(me);
         who=me;
         if((!arg) || (arg != "stone"))
        return notify_fail("��Ҫ��ʲô��\n");
    if ( where->query_temp("temp/ban", 1) || me->query("max_neili")<500)
    {
       message_vision("����ʲôҲû���ˣ�$N����̾�˿�����\n",me);
       return 1;
    }


    where->set_temp("temp/ban", 1);

    message_vision("����$N˫�����䲻ͣ������ʱ��Ὺڣ��ʯ�顣\n", me);




    ob_jian = new(__DIR__"obj/wuming-jian");
    if(!clonep(ob_jian) && !who->query("jinyong/book10")){ 
              return 1;
          }  
    ob_jian->move(where);
    ob_xtj = new(__DIR__"obj/xuantie-jian");
    if(!clonep(ob_xtj) && !who->query("jinyong/book10")){ 
              return 1;
          } 
    ob_xtj->move(where);
  	if((int)who->query("jinyong/book10")==5 && who->query_temp("book1061"))
{
		
		i = 1800+random(2000);
		who->set("jinyong/book10",6);
		who->add("combat_exp",i+15000);
		who->add("potential",i*18);
		who->add("mpgx",10);
		who->add("expmax",2);
		tell_object (who,"��Ӯ����"+chinese_number(i+15000)+"�㾭��"+
		           chinese_number(i*18)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
		who->save();
		 message_vision("$N�ҵ�����������\n", me);
}

    return 1;
}    
    

int do_jump(string arg)
{
	object me = this_player();

	if (me->is_busy()) return notify_fail("����æ���أ�\n");
        
        if (arg != "down")
           return notify_fail("��Ҫ����������\n");
        me->move(__DIR__"qiaobi");
	message_vision("$N����Ծ�����ͱ��ϡ�\n", me);
	
	return 1;
}
