 inherit ROOM;
void create()
{
        set("short", "�������");
        set("long", @LONG
������˵Ҳ�м��������ʷ�ˡ�������ʪ���ƾɲ�����ÿ����紵����������
����ҡ�Σ��ƺ����Ͼͻᵹ�����������������ǲҵ���ֻ��һ֧�����ڷ���ҡҷ��
��������������ɭɭ����������ҳ��������������һ������ɫ������ȴ��һ����
Ⱦ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west"  : __DIR__"nwind5", 
]));
        set("item_desc", ([
                "kan": "������迪�ں�խ�����ÿ�����һ��ֽ(throw)��\n",
                "����" : "������迪�ں�խ�����ÿ�����һ��ֽ(throw)��\n"
        ]) );
        set("objects", ([
                __DIR__"obj/ding_fy" : 1,
                        ]) ); 
        set("coor/x",10);
        set("coor/y",50);
        set("coor/z",0);
        setup();
}
void init()
{
        add_action("do_throw", "throw");
} 
int do_throw(string arg)
{
        object *inv;
        object me, who;
        object paper;
        object killer;
        string target;
        int targetprice;
        int i;
        if (!arg) return notify_fail("��Ҫ��ʲô�����裿\n");
   if( arg !="youzhi" && arg != "���͵�ֽ")
                return notify_fail("�㲻�ɰ�"+arg+"�������裮\n");
        me = this_player();
        who = this_player();
        inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        if( (string)(inv[i]->query("name")) == "���͵�ֽ")
                                {
                                        paper = inv[i];         
                                        break;
                                }
                }
        if( !paper) return notify_fail("��û�����͵�ֽ��\n");
        if( !stringp(paper->query("targetid")))
        return notify_fail("���ֽ��ûд��(print)��\n");
        if( (int) who->query_temp("total_hire") > 1 + who->query("combat_exp")/2000 )
                return notify_fail("���Ѿ���Ӷ̫��ɱ���ˡ�\n");
        
        who->start_busy(2);
        who->add_temp("total_hire", 1);
        target = (string)paper->query("targetid");
        killer = new(__DIR__"npc/killer");
        killer->set("possessed",who);
        killer->set_leader(who);
        killer->set("haunttar", target); 
        targetprice = (int)paper->query("targetprice");
        killer->set("combat_exp", targetprice/10 );
        targetprice = targetprice / 200000 + 1;
        killer->set_temp("apply/attack", targetprice);
        killer->set_temp("apply/move", targetprice);
        killer->set_temp("apply/dodge", targetprice);
        killer->set_temp("apply/damage", targetprice / 2 );
        message_vision("$N��Цһ������Ŀ���µİ�ֽ�������裮\n",who);
        if (paper->query("players"))            // ����Ҫ��¼player target
        log_file("KILL_LOG",sprintf("(%s)%s����ɱ��ɱ%s\n",
                ctime(time()),
                who->query("id"),
                killer->query("haunttar")));
        destruct(paper);
   call_out("gothim", 2, who,killer);
        return 1;
} 
void gothim(object who, object killer)
{
        if(who && killer) {
       message_vision("һ�������ӹ���$N�������˸���ս��\n",who);
        killer->move(environment(who));
        message_vision("$N��$n������������ȥ����\n",killer,who);
        }
        return;
}   
