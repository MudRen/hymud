 // (C)1998-2000 Tie Yu
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
int tell_him();
void create()
{
        set_name("田膨郎", ({ "tianpeng lang","tianpeng" }) );
        set("gender", "男性" );
        set("long","此人双眼大如铜铃，但双眼相距奇远，一看到此人，你就发现他的名字和他本人真象！\n");
        set("age", 45);
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("inquiry", ([
                "药方" : (: tell_him :),
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
        
        if (me->query("m_success/义助袁姬")) {
                tell_object(me,"田膨郎道：我不是给过你了吗？\n");
                return 1;
        }
           if (me->query("combat_exp")<1500000) {
                tell_object(me,"田膨郎道：小孩子不懂别瞎问，乱吃药要死人的。\n");
                return 1;
        }
        if(me->query_temp("marks/yaofang") && !me->query_temp("marks/ami"))    {
                if(me->query_temp("marks/asked_yaofang") <  5)       {
                        tell_object(me,"田膨郎道：噢．．你想要药方．．但你知道不知道这药方会给你杀身之祸？\n");
                        tell_object(me,"田膨郎道：凡是从我这里拿了药方的人一出门就被人刺杀死了，\n");
                        tell_object(me,HIR"无一幸免！！！无一幸免！！！\n"NOR);
                        me->add_temp("marks/asked_yaofang",1);
                        return 1;
                }
                else if(me->query_temp("apply/jade_pro"))        {
                        me->set_temp("marks/ami",1);
                        obj = new(__DIR__"obj/lawan");
                        obj->set("real_lawan_id",me->query("id")); 
                        tell_object(me,"田膨郎道：唉，既然你不怕死．．． \n");
                        tell_object(me,"田膨郎转过身去，不知从那里摸出个腊丸．．． \n");
                        tell_object(me,"就在田膨郎要把腊丸给你的一瞬间，红光一闪，一股血从他的颈动脉喷出．．．
他的手突然僵硬．．．腊丸掉在了地上。\n");
                        obj->move(environment(this_object()));
                        tell_object(me,"你听到你脖子上＂叮＂的一声．．．还好！幸亏戴着玉脖套！！\n");
                        this_object()->die();
                        return 1;
                }
                else       {
                        tell_object(me,"田膨郎道：唉，既然你不怕死．．． \n");
                        tell_object(me,"田膨郎转过身去，不知从那里摸出个腊丸．．． \n");
                        tell_object(me,"就在田膨郎要把腊丸给你的一瞬间，你突然感到脖子上针扎般的痛．．．\n");
                        message_vision(HIR"红光一闪，一股血从$N的颈动脉喷出．．．\n"NOR,me);
                        if (!me->query("m_success/义助袁姬")) {
                                me->set("m_success/义助袁姬",2);
                                tell_object(me,HIM"在生命离你而去的刹那，你似乎有些遗憾，似乎又没有。。。。\n"NOR);
                                message_vision(HIR"鲜血染红了$N的身体，像盛开的杜鹃花般绚烂．．．\n"NOR,me);
                                n = random (20);
                                switch( random(4)){
                                        case 0: me->add("score",1000);
                                        tell_object(me,HIW"你的评价增加了一千点！！\n"NOR);
                                        break;
                                case 1: me->add("max_neili",20+n);
                                   me->set("Add_force/义助袁姬",20+n);
                                        tell_object(me,HIW"你的内力增加了。\n"NOR);
                                        break;
                                case 2: me->add("max_atman",20+n);
                                        me->set("Add_atman/义助袁姬",20+n);
                                        tell_object(me,HIW"你的灵力增加了。\n"NOR);
                                        break;
                                case 3: me->add("max_mana",20+ n);
                                        me->set("Add_mana/义助袁姬",20+n);
                                        tell_object(me,HIW"你的法力增加了。\n"NOR);
                                        break;
                                default: break;
                        }
                        tell_object(me,HIR"你解开了义助袁姬之谜。\n"NOR);
                }
                me->die();
                return 1;
                }
                return 1; 
    }
    message_vision("$N说：“药方？什么药方？没听说过。“\n",this_object());
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
