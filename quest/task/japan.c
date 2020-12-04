#include <ansi.h>
inherit NPC;
#include "/quest/givehdgift.c"
string *nm1_jp =({
"山本","龟田","姿三","大岛","松下","横田","东芝","候本","川野","山口",
"铃木","岗仓","小岛","井上","安奈","浅田","佐藤","广末","大竹","大村",
"伯佐","富冈","东乡",
});

string *id_jp =({
"shanben","guitian","zisan","dadao","songxia","hengtian","dongzhi","houben","chuangye","shankou",
"lingmu","gangcang","xiaodao","jinshang","annai","qiantian","zuoteng","guangmu","dazhu","dachun",
"bozuo","fugang","dongxiang",
});    
    
string *nm2_jp =({
"太郎","次郎","三郎","四郎","五郎","十一郎","十四郎","二十六","俊树",
"宁次","英机","冶字","俊雄","牧夫","光夫","敬一","英世","漱石","渝吉",
"一叶","子规","稻造","伊冲","松园","深水","大观","丰国","孝和","茂",
"川","卫","岛寿","光云","安治","山乐","梦二",
});

void create()
{
   int i = random(sizeof(nm1_jp));
    set_name(nm1_jp[i]+nm2_jp[random(sizeof(nm2_jp))], ({id_jp[i]}));
    set("gender", "男性" );//性别与上面对应
//        set_name("东洋倭寇", ({ "wokou", "japan wokou" }) );
        set("long",
"一个身长不足四尺满脸又是伤疤加横肉的小日本。\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
set("nickname",HIR"倭寇足轻"NOR);
if (random(3)==0) set("nickname",HIR"倭寇家将"NOR);
if (random(4)==0) set("nickname",HIR"倭寇家老"NOR);
if (random(5)==0) set("nickname",HIR"倭寇家督"NOR);
  set("force_factor",2+random(390));
  set("max_qi",1300+random(690));
  set("taskid", 1);
  set("max_jing",1300+random(890));
  set("max_sen",1300+random(890));
  set("max_neili",1300+random(890));
  set("max_mana",1300+random(890));
  set("eff_neili",1300+random(390));
  set("neili",1300+random(1390));
        set("per", 1);
        set("age", 22);
        //set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 400000+random(5000000));
	set("bellicosity", 10000);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),

        }) );
        set("chat_chance", 20);
        set("chat_msg", ({
                "倭寇喝道：男人的,统统的杀啦,杀啦的！！\n",
                "倭寇笑道：花姑娘的,留下,让皇军快活,快活的!\n",
                "倭寇笑道：杀喼喼!统统的杀啦,杀啦的！！\n",
                (: random_move :),
        }) );

        set_skill("unarmed", 80+random(180));
        set_skill("blade", 80+random(180));
        set_skill("parry", 80+random(180));
        set_skill("dodge", 80+random(180));
        set_skill("wind-blade", 280+random(180));
        
        map_skill("blade", "wind-blade");
        map_skill("parry", "wind-blade");
        set_temp("apply/attack", 20);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 20);

        setup();

        carry_object("/clone/misc/cloth")->wear();
        carry_object("/quest/weiguo/japan/obj/japanblade")->wield();
	add_money("silver", random(50));
}
void init()
{
        remove_call_out("leave");
        call_out("leave",180);
}
void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(this_object()->query("name") + "钻进路边的杂草，不见了。\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}

int die()
{
        object ob, me, corpse,who;
        int exp;
        ob = this_object();
        who=ob;
        me = query_temp("last_damage_from");
        
if (me)
{
        message_vision(WHT"$N大叫一声,天皇万岁!!倒地而亡。\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
{
exp=300+random(188);
addnl(me,"exp",exp);
me->add_temp("tjobk",1);
if (me->query_temp("tjobk",1)>=5)
{
if ((int)me->query_temp("tjoblx",1)<7)
{
if (random(2)==0)
"/adm/daemons/taskd"->give_gift3(2,who,me);
else
"/adm/daemons/taskd"->give_gift3(3,who,me);
if (me->query_temp("nhdjob2sc"))
message_vision("$N通过在敌人尸体上查找，得到了一个任务:\n" + me->query_temp("nhdjob2sc") + "。\n", me);
}
me->set_temp("tjobstart",0);
me->set_temp("tjobk",0);
me->delete_temp("tjobstart");
me->delete_temp("tjobk");
me->clear_condition("taskjob_busy");

}
        destruct(ob);
        return 1;
}
}
}
