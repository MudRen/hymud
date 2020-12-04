#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc";  
inherit NPC;
int burn_it(); 
void create()
{
        set_name("����",({"ding qiu","ding"}));
        set("title",HIY"������"NOR);
        set("long","һ����ɫ���׵����Ӵ�����ո�µ��಼���ѣ��ݵþ����Ǹ���������ϵ�
���򡣲������ҵ���˵�����ӵ���û��һ�����������ϡ�\n");
        
        set("gender","����");
        set("age",52);
                
        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",40);
        
        set_skill("unarmed",200);
        set_skill("dodge",150);
        set_skill("parry",160);
        set_skill("force",180);
        set_skill("move",200); 
        
        set("neili",1500);
        set("max_neili",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",6000000);  
        set("attitude", "friendly");
        
        
//      set("death_msg",CYN"\n$N�ں޵�˵�����ҵĽ��������ǡ������εá���̫������������\n"NOR);          
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                100:    (:  burn_it()  :),
        ]) );           
        set("chat_chance_combat", 100);
/*        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );*/
        set("chat_chance",1);
        set("chat_msg",({ 
           }) );                   
        
//        CHAR_D->setup_char(this_object());
//       auto_npc_setup("wang",200,160,1,"/obj/weapon/","fighter_w","thunderwhip",2);
        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
        
    
}  
int burn_it()   {
        object me,ob,coffin,env;
        
        me=this_player();
        ob=this_object();       
        
        coffin=present("coffin",environment(ob));
        
        if (coffin) {
                if (userp(coffin)) {
                        command("say ���������������Ž��ײģ�");
                        message_vision(HIR"$Nһ�ƻ���$n�������ϡ�\n"NOR,ob,coffin);
                        coffin->die();
                        return 1;
                }
                
                if (!coffin->query("burnt") && !coffin->query("burning")) {
                        command("grin");
                        message_vision(HIY"$Nһ�����ó��������ӵ�ȼ�����ײ���һ�ӡ�\n"NOR,ob);
                        coffin->set("burning",1);
                        set("start_time",time());
                        return 1;
                }
                
                if (time()>query("start_time")+20 && !coffin->query("burnt")) {
                        message_vision(HIR"\n���һ�����ײ��������е����ˡ�\n"NOR,ob);
                        coffin->set("burnt",1);
                        coffin->delete("burning");
//                      coffin->set("long", "һ���յúں����Ĺײļ��ӣ�ʲôҲ����������\n");
                        return 1;
           }
                
                if (!coffin->query("burnt"))
                        message_vision(RED"����Խ��Խ�����ˣ��ۿ���Ҫ�������ײ���û��\n"NOR,ob);
                        
                
        }
        return 1;
}  
void die()      {
        
        object coffin,ob;
        
        ob=this_object();
        coffin=present("coffin",environment(ob));
        
        if (coffin->query("burning")) 
                message_vision(HIG"�ײ��ϵĻ��ƽ���С����ȥ��\n"NOR,ob);
        coffin->delete("burning");
        ob->delete("start_time");
        ::die();
}  
int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 5);
                return 1;
        }
        return ::heal_up() + 1;
}  
void leave()
{
        object coffin;
        
        coffin=present("coffin",environment(this_object()));
        
        if (objectp(coffin))
        if (coffin->query("burning")) {
                message_vision(HIR"\n���һ�����ײ��������е����ˡ�\n"NOR,this_object());
                coffin->set("burnt",1);
           coffin->delete("burning");
        }
        message_vision("$Nһ����Ծ��������ʧ�ˡ�\n",this_object() );
        environment(this_object())->set("tuozi_out",0);
        destruct(this_object());
}
          
