#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc"; 
inherit NPC;
int show_me(); 
void create()
{
        set_name("����ӵ�Сϱ��",({"pregnant woman","woman"}));
        set("long","һ������һ���������·���Сϱ����ͦ�Ÿ���������ں͵���Ļ���ּۻ��ۡ�\n");
        
        set("gender","Ů��");
        set("attitude", "friendly");
        set("group","citizen");
        
        set("combat_exp",200000);  
        
        set("age",32);
                
        set("int",40);
        set("cor",40);
        set("cps",40);
        
        set_skill("unarmed",200);
        set_skill("dodge",150);
        set_skill("parry",160);
        set_skill("force",180);
        set_skill("move",200); 
                
        set("max_neili",200+random(500));
        set("neili",query("max_neili"));
        set("force_factor",30);
        
        
        set("inquiry", ([
                
        ])); 
        set("death_msg",CYN"\n$N˵�������ģ��ⲻ��һʬ����ô����\n"NOR);        
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                10: name()+"�е��������˰���ǿ��������\n", 
        ]) );           
        set("chat_chance_combat", 100);
/*        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );*/
        set("chat_chance",1);
        set("chat_msg",({
                name()+"����һ�����������˵�������ɣ������ǿ飿��\n",
           }) );                   
        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
} 
void init()
{       
        object ob;
        
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_answer", "answer");
} 
void greeting(object me)
{
        if( !me || environment(me) != environment() ) return;
        if (me->query("wanma/����Сϱ��")) {
                command("xixi "+me->get_id());
                return;
        } 
        if (me->query("wanma/��Сϱ��")) {
                message_vision(CYN"$N��$n˵�������������ܽ�����\n"NOR,this_object(),me);
                return;
        }
        
        message_vision(CYN"$Nһ����ס$n����˵������λ"+RANK_D->query_respect(me)+"���ҳ�������ɡ���\n"NOR,this_object(),me);
        message_vision(CYN"$N˵������˵�����������أ��������ģ��������̵ģ��Ƶģ���\n",this_object());
        tell_object(me,HIY"���������򡡣��䣯�����壯��������������� \n"NOR);
        me->set_temp("wanma/answer_preg",1);
} 
int do_answer(string arg)
{
        object me,ob,huoji;
        
        me=this_player();
        ob=this_object();       
        
   if(!me->query_temp("wanma/answer_preg")) {
                command("say ����û���㣬��Ϲ����ʲô?");
                return 1;
        }
        
        if(arg=="blue") {
                command("say ��ѽ,�������������,����֪��������,�������ǲµ����Ŀ���ȥ�ˡ�");
                command("say �Ҿ�Ҫ����ˡ�");
                command("say ����,�ҽ�������˴�����,�����ʮ����,֪������ѽ��");
                me->delete_temp("wanma/answer_preg");
                me->set("wanma/��Сϱ��",1);
                return 1;       
        }
        if (arg=="yellow" || arg=="red" || arg=="green") {
                message_vision(CYN"$N�����룬ҡ��ҡͷ˵�������ò��á���\n"NOR,this_object());
                message_vision(CYN"$Nת��ͷȥ������$n�ˡ�\n",this_object(),me);
                me->delete_temp("wanma/answer_preg");
                huoji=present("huo ji",environment(this_object()));
                if (huoji) 
                        message_vision("$N������$n�ļ�ͷ˵������Ů�������������װɣ���\n"NOR,huoji,me);
                return 1;
        }
        tell_object(me,"��ֻ�ܻش���䣯�����壯���������������\n");
        return 1;
} 
int accept_object(object who, object ob)
{
        if (!who->query("wanma/��Сϱ��")) {
                command("say ���ǹ��ؾ��˼ҳ����ģ���ô�������ñ��˵�Ǯ�أ�");
                return 1;
        }
        if (ob->value()>=100000) {
                command("touch "+who->get_id());
                command("say ̫��л�ˣ�����Ҽ��ǿ��Ӵ󷽶��ˣ��Ҿ�����������ģ�");
                if (!who->query("wanma/����Сϱ��")) {
                        who->set("wanma/����Сϱ��",1);
                        who->add("combat_exp",1000);
                        who->add("potential",200);
                        who->add("wanma/����",1);
                        tell_object(who,HIW"�㱻�����ˣ�һǧ��ʵս���飬���ٵ�Ǳ�ܣ�\n"NOR);
                   tell_object(who,HIW"���������ԶС������������ˣ�\n"NOR);
                } 
                return 1;               
        } 
        command("say ���Ǯ������ѽ��");
        command("addoil "+who->get_id());
        return 0;
}                        
                                 
