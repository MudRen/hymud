 // (C)1998-2000 Tie Yu
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
int tell_him();
void create()
{
        set_name("������", ({ "tianpeng lang","tianpeng" }) );
        set("gender", "����" );
        set("long","����˫�۴���ͭ�壬��˫�������Զ��һ�������ˣ���ͷ����������ֺ�����������\n");
        set("age", 45);
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("inquiry", ([
                "ҩ��" : (: tell_him :),
                "yaofang" : (: tell_him:),
        ]));
        	set("vendor_goods", ({
                __DIR__"obj/yu1",
                __DIR__"obj/yu2",
                __DIR__"obj/gu",
                __DIR__"obj/mi",
	})); 
        setup();
        carry_object("/clone/misc/cloth")->wear();
}
void init()
{
		add_action("do_buy", "buy");
	add_action("do_list", "list");
}
int tell_him()
{
        object me,obj;
        int n;
        me =this_player(); 
        
        if (me->query("m_success/����Ԭ��")) {
                tell_object(me,"�����ɵ����Ҳ��Ǹ���������\n");
                return 1;
        }
           if (me->query("combat_exp")<1500000) {
                tell_object(me,"�����ɵ���С���Ӳ�����Ϲ�ʣ��ҳ�ҩҪ���˵ġ�\n");
                return 1;
        }
        if(me->query_temp("marks/yaofang") && !me->query_temp("marks/ami"))    {
                if(me->query_temp("marks/asked_yaofang") <  5)       {
                        tell_object(me,"�����ɵ����ޣ�������Ҫҩ����������֪����֪����ҩ�������ɱ��֮����\n");
                        tell_object(me,"�����ɵ������Ǵ�����������ҩ������һ���žͱ��˴�ɱ���ˣ�\n");
                        tell_object(me,HIR"��һ���⣡������һ���⣡����\n"NOR);
                        me->add_temp("marks/asked_yaofang",1);
                        return 1;
                }
                else if(me->query_temp("apply/jade_pro"))        {
                        me->set_temp("marks/ami",1);
                        obj = new(__DIR__"obj/lawan");
                        obj->set("real_lawan_id",me->query("id")); 
                        tell_object(me,"�����ɵ���������Ȼ�㲻���������� \n");
                        tell_object(me,"������ת����ȥ����֪���������������裮���� \n");
                        tell_object(me,"����������Ҫ����������һ˲�䣬���һ����һ��Ѫ�����ľ��������������
������ͻȻ��Ӳ��������������˵��ϡ�\n");
                        obj->move(environment(this_object()));
                        tell_object(me,"�������㲱���ϣ�������һ�����������ã��ҿ��������ף���\n");
                        this_object()->die();
                        return 1;
                }
                else       {
                        tell_object(me,"�����ɵ���������Ȼ�㲻���������� \n");
                        tell_object(me,"������ת����ȥ����֪���������������裮���� \n");
                        tell_object(me,"����������Ҫ����������һ˲�䣬��ͻȻ�е��������������ʹ������\n");
                        message_vision(HIR"���һ����һ��Ѫ��$N�ľ��������������\n"NOR,me);
                        if (!me->query("m_success/����Ԭ��")) {
                                me->set("m_success/����Ԭ��",2);
                                tell_object(me,HIM"�����������ȥ��ɲ�ǣ����ƺ���Щ�ź����ƺ���û�С�������\n"NOR);
                                message_vision(HIR"��ѪȾ����$N�����壬��ʢ���Ķž黨��Ѥ�ã�����\n"NOR,me);
                                n = random (20);
                                switch( random(4)){
                                        case 0: me->add("score",1000);
                                        tell_object(me,HIW"�������������һǧ�㣡��\n"NOR);
                                        break;
                                case 1: me->add("max_neili",20+n);
                                   me->set("Add_force/����Ԭ��",20+n);
                                        tell_object(me,HIW"������������ˡ�\n"NOR);
                                        break;
                                case 2: me->add("max_atman",20+n);
                                        me->set("Add_atman/����Ԭ��",20+n);
                                        tell_object(me,HIW"������������ˡ�\n"NOR);
                                        break;
                                case 3: me->add("max_mana",20+ n);
                                        me->set("Add_mana/����Ԭ��",20+n);
                                        tell_object(me,HIW"��ķ��������ˡ�\n"NOR);
                                        break;
                                default: break;
                        }
                        tell_object(me,HIR"��⿪������Ԭ��֮�ա�\n"NOR);
                }
                me->die();
                return 1;
                }
                return 1; 
    }
    message_vision("$N˵����ҩ����ʲôҩ����û��˵������\n",this_object());
    return 1;
} 
void reset()
{
        set("vendor_goods", ([
                __DIR__"obj/yu1":8,
                __DIR__"obj/yu2":8,
                __DIR__"obj/gu":10,
                __DIR__"obj/mi":8,
        ]) );
}  
