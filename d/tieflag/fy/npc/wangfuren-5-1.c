 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("������", ({ "furen" }) );
        set("gender", "����" );
        set("title", HIR "����ʦ"NOR);
        set("age", 52);
        set("long",
                "�����˱������幬��һ���ϵ�ʿ���˵������������£�
��������˼�����\n");
        set("combat_exp", 50000);
    set("str",30);
        set("attitude", "friendly");
        set("busy", 0);
        setup();
        carry_object("/clone/misc/cloth")->wear(); 
} 
void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 2, ob);
        }
//        add_action("do_ji","ji");
//        add_action("do_answer", "answer");
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if (present("hell sword", ob)) {
//              if (random(4)){
                if (ob->query("����A") || ob->query("����B")){
                        if(ob->query("stone_mark/pstone")){
                                message_vision("\n$N΢��˫�ۿ��˿�$n����ڤ���齣���������ε�����ڤ���齣����ֻ��һ�ѣ���һ�Ѷ�Ϊ��Ʒ��\n",
                                           this_object(), ob);
                                return;
                        }
                        message_vision(HIY"\n$N������͸�����еĹ⣬������ڤ���齣���૵�˵�����������ǧ������\n"NOR, this_object());
                        message_vision(HIY"����ڤ�Ͼ����ɵİ�����ϧұ��֮�˲����䷨�������˵ظ�֮�䡣��\n"NOR, this_object());
                        message_vision("\n$N˵�������" + RANK_D->query_respect(ob) 
+ "Ը���԰ٽ��������ҿ��԰���ڤ�Ͼ�������ԭ����\n" +
"���������򡡣���󣯣�� ��\n", this_object()); 
                        ob->set_temp("furen_yes_no", 1);
                } else {        
                        message_vision(YEL"$N���۹�ɨ��$n����ڤ���齣���۹�������ĥ��͸��\n"NOR, this_object(), ob);
                }
        } else {
                switch( random(5) ) {
                        case 0:
                                say( "������Ц������λ" + RANK_D->query_respect(ob)
                                        + "����ı��п���������ҪѪ��һ���ˡ�\n");
                                break;
                        case 1:
                                say( "������˵������λ" + RANK_D->query_respect(ob)
                                        + "����ı���ɱ�����㣬��Ѫ��һ�±��аɡ�\n");
                                break;
                }
        }
}
int do_answer(string arg) {
        object me, stone, gold;
        
        me = this_player();
        gold = present("gold_money", me);
        if (!me->query_temp("furen_yes_no")) {
                return 0;
        }
        if (!arg || arg == "no") {
                message_vision("\n$N˵��������ϧ������ڤ�Ͼ�ѽ����\n", this_object());
                return 1;
        }
        if (arg == "yes") {
                me->set("marks/����ڤ�Ͼ�", 1); 
                message_vision("$N˵�������ã���\n", me);
           return 1;
        }
} 
int accept_object(object who, object ob) {
        object me, sword;
        
        me = this_player();
        sword = present("hell sword", me);
        if (!me->query("marks/����ڤ�Ͼ�")) {
                return 0;
        }
        if (ob->query("money_id") != "gold") {
                        return 0;
        } else {
                if (ob->query_amount() < 100 ) {
                        return 0;
                } else {
                        if (this_object()->query("busy")) {
                                return 0;
                        } else if (present("hell sword", me)) {
                                message_vision("\n$N��$n����ȡ����ڤ���齣������ұ��¯�С�\n", this_object(), me); 
                                destruct(sword);
                                message_vision(HIC"¯�𽥽��Ӻ�ɫת�����֮ɫ��\n"NOR, this_object());
                                set("busy", 1);
                                call_out("ext_stone", 3, me);
                        } else {
                                return 0;
                        }
                }
        }       
        return 1;
} 
int ext_stone(object me){
        object stone;
        if (environment(me) == environment(this_object())) {
                message_vision(MAG"\n��Ȼ�䣬�Ϲ���ҫ��ӳ����ء�\n"NOR, this_object()); 
                message_vision(HIR"$N��Ȼ�õ����Լ����ֱ���һ����һ��Ѫ������ұ��¯��\n"NOR, this_object()); 
                message_vision(MAG"\n�Ϲ��ʢ֮�£��㲻�ɵñ����۾���\n"NOR, this_object());
                message_vision("���ۿ�ʱ���������ѽ�һ���Ĺ���������ʯ�������С�\n", this_object()); 
                me->delete("marks/����ڤ�Ͼ�"); 
           stone = new("/obj/specials/stone/pstone");
                stone->move(this_object());
                if(!me->query("stone_mark/pstone")){
                me->set("stone_mark/pstone",1);
                me->add("score",3000);
                }
                command("give amethist to " + me->query("id"));
        } 
        set("busy", 0);
        return 1;
}
int  do_ji(string arg)
{
        object me, ob;
        object gold;
        int cost = 1;
        int i,j,base,current;
        string id,name,broken;  
        string file,newfile,filestring;
        me = this_player();
        id = me->query("id");
        if( !arg ) return notify_fail("��Ҫ��ʲ��������\n");
        gold = present("gold_money", this_player());
        if( !gold) return notify_fail("������û�н��ӡ�\n");
        if( !objectp(ob = present(arg, me)) )
        return notify_fail("������û������������\n");
        if(me->is_busy())
        return notify_fail("����һ��������û����ɡ�\n");
        if( !ob->query("weapon_prop") )
        return notify_fail("��ֻ�ܼ��ɵ��������Ķ�����\n");
        if( ob->query("equipped") )
        return notify_fail("�㲻�ɼ�װ�����˵�������\n");
        if( !ob->query("owner") )
        return notify_fail("��ֻ�ɼ��Լ������������\n");
        sscanf(ob->query("name"),"%s��",broken);
        if(broken=="�ϵ�")
        return notify_fail("�㲻�ɼ����˵���������ȥ�������������������������\n");
        base= (int)ob->query("base_damage");
        current = (int) ob->query("weapon_prop/damage"); 
/*      for(j=1;j<=100;j++)
   {
                base = base + j;
                if(base >= current) break;
        }*/
        if(!ob->query("ji_times")) {
                j = 1;
        } else {
                j = ob->query("ji_times");
        }
        for(i=1; i<=j;i++)
                        cost = cost * 2;
        if((int) gold->query_amount() < cost)
        return notify_fail("������û����" + sprintf("%d",cost)+ "�����ӡ�\n");
        gold->add_amount(-cost);
        me->start_busy(1);
        me->add("bellicosity",cost);
        seteuid(ROOT_UID);
// need to update 3 things: damage, rigidity, and weight, base_damage is to keep track
// damage on weapon so we can xiu weapon later on.
        ob->add("weapon_prop/damage",j);
    ob->add("base_damage", j);
        ob->set("weight",(int)ob->query("weight")+j*100);
        ob->add("rigidity",j*10);
        ob->add("ji_times", 1);
        ob->save();
        ob->restore();
        if(ob->move(me))         {
        message_vision("\n$N��$n����ȡ��"+ob->name()+"������ұ��¯�С�\n", this_object(), me); 
        message_vision(HIC"¯�𽥽��Ӻ�ɫת�����֮ɫ��\n\n\n"NOR, this_object());
        message_vision(HIR"$N��Ȼ�õ����Լ����ֱ���һ����һ��Ѫ������ұ��¯��\n"NOR, this_object()); 
        message_vision(HIC"\n¯����֮�£��㲻�ɵñ����۾���\n"NOR, this_object());
        message_vision("$N˵�������ˣ�\n\n",this_object());
        message_vision("���ۿ�ʱ���������ѽ�$n�����������С�\n", this_object(), ob); 
        seteuid(getuid());
        }
        return 1;
}  
