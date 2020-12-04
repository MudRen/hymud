#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc"; 
inherit NPC;
int show_me();
int kill_him(); 
void create()
{
        set_name("�θ���",({"song fugui","fugui","song"}));
        set("title","�޻����ϰ�");
        set("long","�θ�����ֻ�Ǹ������ʮ�����걻�޻����ϰ�Ĺ�Ů������������Ů����
��ô�������������㣬�Ѹ��޻��е�����Խ��Խ�죬Խ��Խ��\n");
        
        set("gender","����");
        set("attitude", "friendly");
        set("group","citizen");
        
        set("combat_exp",4000000);  
        set("age",42);
                
        set("int",40);
        set("cor",40);
        set("cps",40);
        
        set_skill("unarmed",200);
        set_skill("dodge",150);
        set_skill("parry",160);
        set_skill("force",180);
        set_skill("move",200); 
                
        set("max_atman",random(1000));
        set("atman",query("max_atman"));
        set("max_mana",random(500));
        set("mana",query("max_mana"));
        set("max_neili",1000+random(500));
        set("neili",query("max_neili"));
        set("force_factor",100);
        
        set("resistance/kee",random(30));
        set("resistance/gin",random(30));
        set("resistance/sen",random(30));
        
        set("inquiry", ([
                "ɽ��" :        (: show_me :),
                "bandit" :      (: show_me :),
                "�����嶾":     (: kill_him :),
                "��������":     (: kill_him :),
        ])); 
//         set("death_msg",CYN"\n$N�ں޵�˵�����ҵĽ��������ǡ������εá���̫������������\n"NOR);          
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                10: name()+"�е��������˰���ǿ����ٵ���������\n", 
        ]) );           
        set("chat_chance_combat", 100);
/*        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );    */
        set("chat_chance",1);
        set("chat_msg",({
                name()+"��ü������˵����ɽ��һ���һ���Ᵽ��������ô��������ȥ�ǣ���\n",
        }) );                   
        
//        CHAR_D->setup_char(this_object());
//        auto_npc_setup("wang",200,165,0,"/obj/weapon/","fighter_w","taiji",2);
        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
        add_money("gold", random(3));
} 
void init(){
        add_action("do_answer","answer");
}  
int kill_him()
{
        object me, another;
        object ob;
        
        ob=this_object();
        me = this_player();
        if (this_object()->is_fighting()) {
                tell_object(me,"�θ�������û�ջش��㡣\n");
                return 1;
                }
        message_vision(CYN"$N���Ϻ�Ȼ¶�����䵭�����ص�΢Ц������Ц�ݱ����ó������ϵġ�\n"NOR,this_object());
        message_vision(CYN"$N����Ц�ŵ�������Ȼ��֪���ˣ��Ͳ��������ٻ��ų�ȥ��\n",this_object());
        another = new(__DIR__"huahua");
        another->move(environment(this_object()));
        destruct(ob);
   return 1;
}  
int show_me()   {
        object me,ob;
        
        me=this_player();
        ob=this_object();
        if (me->query("wanma/ƽɽ��")) {
                command("say �����ɨƽɽ�����ҵ������ֺ������ˡ�");
                return 1;
        }
        command("say ����ǰ����֪���Ķ�����һ��ǿ�ˣ�ÿ�����ʱ������ڴ�١�");
        command("say ���ϵ�����һ�첻��һ�죬ǿ����ȴԽ���䱾����������ǰ���Ҵ��ڵ����������Ѷ����ˡ�");
        command("sigh");
        command("say ���޻��п����ǿ�����ȥ�ˣ���λ"+RANK_D->query_respect(me)+"�ܲ��ܾ���һ����");
        tell_object(me,HIY"���������򡡣���󣯣� \n"NOR);
        me->set_temp("wanma/answer_song",1);
        return 1;
}  
int do_answer(string arg)
{
        object me,ob;
        
        me=this_player();
        ob=this_object();       
        
        if(!me->query_temp("wanma/answer_song")) return 0;
        if(arg=="yes") {
                message_vision(YEL"$N�ᶨ�ص��˵�ͷ˵������ƽ��������ѧ��֮����ְ����\n"NOR,me);
                command("say �ã��ã����ɽ��������ҹ���û�����⣬��˵���������졣");
                command("say ϣ�����ܽ�����һ�ٲ��������һ��ҵĻ��");
                me->delete_temp("wanma/answer_song");
                me->set("wanma/׼��ɱɽ��",1);
                return 1;       
        }
        if(arg=="no"){
                message_vision(CYN"$N�Ͻ�ҡ��ҡͷ˵�����������յ�΢���㻹����������ɡ���\n"NOR,me);
                message_vision(YEL"$N̾�˿���˵�����������ˣ����ˣ���\n"NOR,ob);
                me->delete_temp("wanma/answer_song");
                return 1;
   }
        tell_object(me,"��ֻ�ܻش�������\n");
        return 1;
}  
int accept_object(object who, object ob)
{
        if (ob->name()=="����") {
                if (!who->query_temp("wanma/��������") || !who->query_temp("wanma/������")
                        || !who->query_temp("wanma/���ϻ�")) {
                                command("say лл�������һ��˻�������������ɱ���Ǽ���ɽ��ͷ�ӣ����ǿ϶���������ġ�");
                                command("sigh");
                                return 1;
                } else {
                        command("touch "+who->get_id());
                        command("say ̫��л�ˣ��Ҿ���������Ӣ�۵Ĵ����µģ�");
                        if (!who->query("wanma/ƽɽ��")) {
                                who->set("wanma/ƽɽ��",1);
                                who->add("combat_exp",1000);
                                who->add("potential",200);
                                who->add("wanma/����",1);
                                tell_object(who,HIW"�㱻�����ˣ�һǧ��ʵս���飬���ٵ�Ǳ�ܣ�\n"NOR);
                                tell_object(who,HIW"���������ԶС������������ˣ�\n"NOR);
                        } else {
                                who->add("combat_exp",400);
                                who->add("potential",50);
                                tell_object(who,HIW"�㱻�����ˣ��İٵ�ʵս���飬��ʮ��Ǳ�ܣ�\n"NOR);
                        }
                        who->delete_temp("wanma/��������");
                        who->delete_temp("wanma/������");
                        who->delete_temp("wanma/���ϻ�");
                        return 1;
                }       
        }
        return 0;
}                        
                              
