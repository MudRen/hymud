#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�й�", ({ "jia gun", "jiagun" }) );
        set("long",
                "�й�����һ�������Ĳ�ͷ���������ͺ���ֻ��Ƥ���Ź�ͷ����û�б�\n�飬Ҳû���⡣�۾���ɭɭ�ģ���С���������ϼ��������ǵ�ʵ��Ҫ\n�����Ƴ�����Ҳ����ƨ��Ҫ���ų�����\n");
        set("chat_chance",1);
        set("chat_msg", ({
                        "�й���ɭɭ�������㣬�������������ʾ������������У��Ϳ��õ�\n���ƣ�������׽�÷�����鰸���������͡���\n",
                                })  ); 
        set("combat_exp", 280000 + random(100000));
        set("max_jing",1000);
        set("max_qi",1000);
        set("max_jing",1000);
        set("max_neili",600);
        set("force",1200);
        set("force_factor",30);
        
 set_skill("qixian-wuxingjian", 380);
set_skill("cuff", 300);
set_skill("cuff", 300);
set_skill("lingshe-quan", 380);
set_skill("zhaosheshu", 380);
set_skill("yangsheshu", 380);
	set_skill("sword", 280);
	set_skill("force", 250);
	set_skill("unarmed", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("strike",320);
	set_skill("hand",320);
	set_skill("training",380);
	set_skill("staff", 250);
	set_skill("hamagong", 380);
	set_skill("chanchu-bufa", 380);
	set_skill("shexing-diaoshou", 380);
	set_skill("lingshe-zhangfa", 380);
	set_skill("hamashengong", 380);
	set_skill("xiyu-tiezheng", 380);
set_skill("shentuo-zhang", 380);
	map_skill("strike", "hamagong");
	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("unarmed", "shexing-diaoshou");
	map_skill("hand", "xiyu-tiezheng");
	map_skill("parry", "hamagong");
	map_skill("staff", "lingshe-zhangfa");
	prepare_skill("strike", "hamagong");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "reserve" :),
                (: perform_action, "staff.saoluoye" :),
                (: perform_action, "staff.shewu" :),
                (: perform_action, "staff.shoot" :),
                (: perform_action, "staff.saoluoye" :),
                (: command("unwield shengzhang") :),
                (: command("wield shengzhang") :),
                (: command("zhaoshe") :),
                (: perform_action, "strike.hama" :),                
               (: perform_action, "strike.puji" :),                
	              (: perform_action, "strike.tui" :),                
		          (: perform_action, "strike.zhen " :),                
                (: perform_action, "hand.shewu" :),                
             
        }) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/shawei")->wield();
}  
void init(){
        ::init();       
        if( !query_heart_beat(this_object()) ) set_heart_beat(1);
   add_action("do_accept", "accept");
}  
void heart_beat()
{
        object ob,me;
        
        if(me=query("test_target"))
        if(query("accept_test")==1)
        {
                say("\n�й����˵�ͷ��˵�����ܺã����ǵ�һ��....\n\n");
                COMBAT_D->do_attack(this_object(), me, query_temp("weapon"));
                
                if( me->query_temp("last_damage_from") ==this_object() || !present(me, environment())) 
                {
                        say("�й���м��˵��������һ�ж��Ų���������̫����....\n");
                        delete("accept_test");
                }
                else add("accept_test",1);
       }
       else if(query("accept_test")==2)
       {
                say("\n�й�˵�������ǵڶ���....\n\n");
                COMBAT_D->do_attack(this_object(), me, query_temp("weapon"));
                if( me->query_temp("last_damage_from") ==this_object() || !present(me, environment())) 
                {
                        say("�й����ߡ���һ����˵������㹦��Ҳ�ҳ�����....\n");
                        delete("accept_test");
                }
                else add("accept_test",1);
        }
        else if(query("accept_test")==3)
        {
                say("\n�й�˵��������������....\n\n");
                COMBAT_D->do_attack(this_object(), me, query_temp("weapon"));
                if( me->query_temp("last_damage_from") ==this_object() || !present(me, environment())) 
                {
                        say("�й�������ȥ��������....\n");
                        delete("accept_test");
                }
                else add("accept_test",1);
        }
        else if(query("accept_test")==4)
        {
                say("\n�й�����Ц��˵�������и������İ����ˣ�\n\n");
                ob = new(__DIR__"obj/yaopai");
                ob->move(me);
                write("�й���"+me->query("name")+"һ�����ơ�");
                me->set_temp("yaopai",1);
                say("\n�й�˵���������ƾ����������ɳ��롣�����˿��������������֪������Э���참���ˡ�\n\n");
                delete("accept_test");
        }
        ::heart_beat();
}  
int do_accept(){
        mapping guild;
        object ob;
                
        if(!this_player()->query_temp("jiegaoshi")){
                return 0;
        }
        if(query("accept_test")){
                return notify_fail("�й�����æ���Ժ�һ�¡�\n");
        }
        set("accept_test",1);
        set("test_target",this_player());
        this_player()->delete_temp("jiegaoshi");
        if( this_player()->query_temp("last_damage_from")) {
                this_player()->delete_temp("last_damage_from");
        }
        heart_beat();         
        return 1;
} 
void die(){
        object ob;
        object *enemy;
        
        ob = query_temp("last_damage_from");
        if(!ob) { 
                enemy = this_object()->query_enemy();
                if(sizeof(enemy))
                   ob=enemy[0];
        } else {
                if(userp(ob)) {         
                        ob->set_temp("marks/killjia",1);
                }
        }
        ::die();
}
                                    
