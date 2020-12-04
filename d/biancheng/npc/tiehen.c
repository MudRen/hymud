#include <ansi.h>
#include <command.h> 
//inherit "/d/taiping/npc/smart_npc"; 
inherit NPC;
void create()
{ 
        set_name("����",({"tie hen","tie"}));
        set("nickname","��������");
        set("title",WHT"�Ĵ�����"NOR);
        set("long", "
һ�����ӱ�ǹ���ͦ�ĺ����ˣ���Į�������п��������������������Ĵ���
���еġ��������顱�����޵����ҳ����ӣ�����С�ˡ������������������Ƶľް���
�Ѳ�֪�ж��١���\n");
        set("age",47);
        set("combat_exp", 7000000);
        set("attitude", "friendly");    
        
        set("force_factor",100); 
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",100);
        
        set_skill("unarmed",200);
        set_skill("dodge",150);
        set_skill("parry",160);
        set_skill("force",180);
        set_skill("move",200); 
        
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        
        //set_skill("dual-attack",200);
        
        set("chat_chance_combat", 100);
/*        set("chat_msg_combat", ({
                (: auto_smart_fight(30) :),    
        }) );*/
                
//        auto_npc_setup("xuebin",250,190,0,"/obj/weapon/","fighter_w","dragonstrike",2);
        setup();
        carry_object(__DIR__"obj/blackcloth")->wear();
        carry_object(__DIR__"obj/jade");
} 
void init() {
        
   object ob;
        ::init();
        add_action("do_answer","answer");
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}  
void greeting(object ob) {
        
        if( !ob || environment(ob) != environment() || ob->is_fighting()) return;
        call_out("ask_question_1",1,ob); 
} 
int ask_question_1(object who)
{
        
        if (who->query("parrot/��̫ƽ��",1)) {
                message_vision(CYN"$N��$n˵������ô������������ô����\n"NOR,this_object(),who);
                return 1;
        }
        if (who->query("m_killer/������") && !who->query_temp("parrot/t_question_1")
                && !who->query("parrot/t_question_1")) {
                message_vision(HIR"\n$N����$nһ��˵����֪��������һ��ʮ�ˣ���Ȼ��һҹ֮�����øɸɾ�������
�º�����û�й�ϵ����\n",this_object(),who);
                tell_object(who,HIY"���������򡡣���󣯣� \n"NOR);
                who->set_temp("answer_person",1);
                who->set_temp("parrot/t_question_1",1);
                return 1;
        }
        if (who->query("parrot/listen_to_story") && !who->query_temp("parrot/t_question_2")
                && !who->query("parrot/t_question_2") ) {
                message_vision(HIR"\n$N����$nһ��˵�������ڵ�������ǰ���������鱦ʧ��һ�������ӵ��ֵܹ���
��˵Ǳ���ڴˣ����Ƿ��������\n",this_object(),who);
                tell_object(who,HIY"���������򡡣���󣯣� \n"NOR);
                who->set_temp("answer_person",2);
                who->set_temp("parrot/t_question_2",1);
                return 1;
        }
        //��������
/*        if (who->query("parrot/t_question_1") && who->query("parrot/t_question_2")
                &&!who->query_temp("parrot/t_question_3")) {
           message_vision(HIR"\n$N˵���ã�����������ʿ����֪�Ƿ�Ը����������һ�£���\n",this_object(),who);
                tell_object(who,HIY"���������򡡣���󣯣� \n"NOR);
                who->set_temp("answer_person",3);
                who->set_temp("parrot/t_question_3",1);
                return 1;
        }   */
} 
int do_answer(string arg)
{
        object who,*inv,jade;
        int i, gotit;
        
        who=this_player();
        
        if(!who->query_temp("answer_person")) return 0;
        if (who->query_temp("answer_person")==1) {
                if(arg=="yes")
                {
                        message_vision(CYN"$N���˵�ͷ��\n"NOR,who);
                        message_vision(CYN"$N����Ц������ɱ���Ǹ�ɱ���ˣ�ɱ�˺���ֶ�ȥ����ȡ���ģ��������\n",this_object());
                        who->delete_temp("answer_person");
                        who->set("parrot/t_question_1",1);
                        call_out("ask_question_1",1,who);
                        return 1;       
                }
                if(arg=="no"){
                        message_vision(CYN"$N�Ͻ�ҡ��ҡͷ��\n"NOR,who);
                        message_vision(CYN"����˵��������׷���׷���������ͺá�\n"NOR,who);
                        who->delete_temp("answer_person");
                        return 1;
                }
        }
        if (who->query_temp("answer_person")==2) {
                if(arg=="yes")
                {
                        message_vision(CYN"$N���˵�ͷ��\n"NOR,who);
                        message_vision(CYN"$N�������ã�����Ȼ��������Ӳ����ˡ���\n"NOR,this_object());
                        who->delete_temp("answer_person");
                        who->set("parrot/t_question_2",1);
                        call_out("ask_question_1",1,who);
                   return 1;       
                }
                if(arg=="no"){
                        message_vision(CYN"\n$N�Ͻ�ҡ��ҡͷ��\n\n"NOR,who);
                        message_vision(CYN"$N�ȵ����󵨣������������������棬Ϊ�����������ҵ�������ȥ˵����\n"NOR,this_object());
                        who->delete_temp("answer_person");
                        this_object()->kill_ob(who);
                        who->kill_ob(this_object());
                        return 1;
                }
        }
        if (who->query_temp("answer_person")==3) {
                if(arg=="yes")
                {
                        message_vision(CYN"$Nһ���֣����¶�����ͷ�����ĳ������Ѿã��Ҳ�������\n"NOR,who);
                        command("spank "+this_player()->get_id());
                        message_vision(CYN"$N�������ã���׷��̫ƽ����һ���������꣬����ǰ���ִ��������ڳ���ʧ��
���鱦���Ѿ��Ļ���������������ʱ��ȴͻȻ���������������������ġ����֡���
����������Դ������һ������̫ƽ��ĵط�����������˿��׷�����ˣ�ȴ����
�������˼��ӽ�ɱ���ҿ�����ɱ���ߺ�ɽׯ������������������֮ʱ���Ѿ�֪��
����һ������Ľ��ͣ���������������һ��֮�����ȵ�̫ƽ�򿱲飬���Ҵ򷢵���
��֮���������ϡ�̫ƽ����С�������ѷ֣����账��С�ģ��������¡���\n"NOR,this_object());
                        
                        inv=all_inventory(this_object());
                        for (i=0;i<sizeof(inv);i++){
                                if (inv[i]->query("id")=="jade") gotit=1;
                        }
                        if (!this_player()->query("parrot/��̫ƽ��") && !gotit) {
                                jade=new(__DIR__"obj/jade");
                                jade->move(this_object());
                                gotit=1;
                        }
                        if (gotit) {
                                command("give jade to "+this_player()->get_id());
                                message_vision("$N�ֵ��������ƾ�˱���ȥ��һ����Τ�����Ů�ӡ���\n",this_object());
                        }
                        who->delete_temp("answer_person");
//      finish with �س� riddle, "parrot/��̫ƽ��" is the mark to carry on. 
//      If the player loses the jade, kill tie hen can get one.
                        who->set("parrot/��̫ƽ��",1);
                   who->delete("parrot/t_question_1");
                        who->delete("parrot/t_question_2");
                        return 1;       
                }
                if(arg=="no"){
                        message_vision(CYN"$N��ԥ������ҡ��ҡͷ��\n"NOR,who);
                        message_vision(CYN"$Nʧ����̾�˿���˵���˸���־���Ҳ���ǿ��\n"NOR,this_object());
                        who->delete_temp("answer_person");
                        return 1;
                }
        }
        return 0;
}        
