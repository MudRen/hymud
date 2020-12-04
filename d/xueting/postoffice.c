// Room: /d/snow/postoffice.c

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "����¯");
        set("long", @LONG
����ԭ����ѩͤ����վ�����ڳ���û��ʲô���£�ѩͤ������
���ó��ˡ������������һ���޴������¯�����ſ�������һ��ľ
��(sign)������д��Щ�֡�
LONG
        );

        set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "������д����
    Ŀǰ����¯���ʹ�ã����ֻҪ���ϴ����˿�ʯ��̿��
����tilian�Ϳ����ˡ�����Ҫ�Ա���������Ŷ��
=======================================================
            ����        ԭ��         ����
-------------------------------------------------------
������ͭ    tilian qt   ������ͭʯ   ����ľ̿





=======================================================
",
]));
        set("exits", ([ /* sizeof() == 1 */
                "east" : __DIR__"street01",
        
        ]));
        
 //       set("objects", ([
  //              __DIR__"npc/post_officer": 1
  //      ]) );
        set("no_beg",1);
        set("no_sleep_room",1);
        set("indoors", "xueting");
        setup();
}

void init()
{
        add_action("do_tilian", "tilian");
}
int do_tilian(string arg)
{
        object me,ob,*inv;
        int i,s,t,sk;
        me = this_player();
        sk = 10+random(250);
        sk = sk + sk;
           if(me->is_busy())
        	return notify_fail("������æ��\n");     
        if( (arg != "qingtong") && (arg != "qt") )
		return notify_fail("  �Բ���Ŀǰֻ��������ͭ�������ݲ����š�\n");
        
        inv = all_inventory(me);
        s=0;
        t=0;
        for(i=0; i<sizeof(inv); i++)
		{
		if ( inv[i]->name() == CYN"��ͭʯ"NOR ) {s=s+1;}
		if ( inv[i]->name() == CYN"ľ̿"NOR ) {t=t+1;}
		}

	if (s<3)
		return notify_fail("  �����ϴ�����ͭʯ��������ȥ�ҵ��ʯ��˵�ɡ�\n");
	if (t<3)
		return notify_fail("  �����ϴ���ľ̿��������ȥ�ҵ�̿����˵�ɡ�\n");
		
	// - ȥ��ҵ�ԭ��
	s=3;
	t=3;
	for(i=0; i<sizeof(inv); i++)
		{
		if ( inv[i]->name() == CYN"��ͭʯ"NOR )
			{
			if (s>0) 
			{
				message_vision(HIY"$N��һ"+inv[i]->query("unit")+inv[i]->name()+HIY"Ͷ������¯��\n"NOR,me);
				destruct(inv[i]);
				s=s-1;
				}
			}
		}

	inv = all_inventory(me);

	for(i=0; i<sizeof(inv); i++)
		{
		if ( inv[i]->name() == CYN"ľ̿"NOR )
			{
			if (t>0)
			{	message_vision(HIY"$N��һ"+inv[i]->query("unit")+inv[i]->name()+HIY"Ͷ������¯��\n"NOR,me);
				destruct(inv[i]);
				t=t-1;
				}
			}
		}
        if(me->query("qi")<20)
        	return notify_fail("  ������������ˣ���������Ϣһ�°ɡ�\n");
        if(me->query("jing")<20)
        	return notify_fail("  ��ľ��������ˣ���������Ϣһ�°ɡ�\n");

//��ѯ�����û���ھ򹤾ߡ�
//    if(!sizeof( inv = filter_array(all_inventory(me),
//		(: $1->is_mine_tool() && $1->tool_can_use() :)) ) )
//		return notify_fail("������û�������ھ�Ĺ��ߡ�\n");
//        me->start_busy(2);

        message_vision(HIR"$Nֻ��¯��Խ��Խ������ʯҲ�����ڻ��ˡ���\n"NOR,me);
        

        // ֱ�Ӽӳ����������ϵͳ����
        i = me->query("kar") + me->query("str") + me->query("int");
        
	//1 �Ƿ���Եõ���ͭ��
	if ( (random(sk+i) ) > ( (sk+60)*9/10) )
	{
		message_vision( HIR"$N����ǯ������������ᵹ��ɳģ��...\n"NOR, me);
		message_vision( HIY"$N������ͭ�ɹ��ˣ�����\n"NOR,me);
                me->receive_damage("qi", 20);
        	me->receive_damage("jing", 20);

                ob = new(__DIR__"kuangshi/qingtong");      
                ob->move(me);
                return 1;
        }
        message_vision("$N����ǯ����������־�Ȼ������һ�£�ͭˮ����һ�ء�\n",me);
        message_vision("$N������ͭʧ����......\n",me);
        me->receive_damage("qi", 10);
        me->receive_damage("jing", 10);
       me->start_busy(16);
        return 1;
        
}