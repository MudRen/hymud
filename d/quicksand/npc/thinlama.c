 inherit NPC;
#include <ansi.h>
void create()
{
        set_name("��������", ({ "travel lama","lama" }) );
        set("gender", "����" );
        set("class", "lama");
        set("age", 32);
        set("str", 25);
        set("dur",100);
        set("cor", 14);
        set("per", 4);
        set("cps", 29);
        set("int", 25);
        set("long", "���������Ÿ�Ъ�ŵ����΢�յı������ϲ�����ɳ����\n");
        set("chat_chance", 1);
        set("chat_msg", ({
                "��������̾�˿������������ȡ�\n",
                "���������������ǧɽ�����̲��������ʲô���������ǹ�������\n��",
                "��������˵������˵�Ϸ�������������������֪��˭�ܰ������ˡ���\n",                
                }) );   
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("max_neili", 500);
        set("neili", 500);
        set("force_factor", 10);

        set_skill("dodge",50);
        set_skill("move",50);
        set_skill("unarmed",50);
        set("skill_public",1);
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
void init() {
        object ob;
        ::init();
        if(interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
   }
} 
void greeting(object ob) {
        if(!ob || environment(ob) != environment()) {
                return;
        }
        switch( random(6)){
                case 0:
                        say("��������̾�˿������������ȡ�\n");
                        break;
                case 1:
                        say("���������������ǧɽ�����̲��������ʲô���������ǹ�������\n��");
                        break;
                case 2:
                        say( "��������˵������˵�Ϸ�������������������֪��˭�ܰ������ˡ���\n");
                        break;
        }
}  
int recognize_apprentice(object ob)
{
        if(ob->query("free_learn/yoga"))
        return 1;
        else {
                if (!random(3)) {
                command ("say ����ֻ�ύӢ�ۺú���\n");
                } 
                return 0;
        }
}  
int accept_object(object who, object ob)
{       
        if (ob->query("name")==HIR "������Ƥ" NOR)
        {
                message_vision("$N���۷ų���������������Ƥ����������ɱ������������\n\n",this_object(),this_player());           
                if( who->query("m_success/����")) 
                { 
                command("praise"+who->query("id"));
                message_vision(HIR"$Nһ���֣�����·������Ӣ���������������¶�һ��ǿ������ؾ�����Ӣ�۷���\n"NOR,this_object(),this_player());
                who->set("free_learn/yoga",1);
                return 1;
           }
                else {
                        message_vision(HIW"$N�ٺ���Ц�˼�����\n"NOR,this_object(),this_player());
                        message_vision(HIW"$N˵����������Ҳ��������ĳ���֮����\n"NOR,this_object(),this_player());
                        message_vision(HIW"��������Ƥ�����ˣ��㣬�������ˡ���\n"NOR,this_object(),this_player());
                //      command("say ����Ҳ��������ĳ���֮��\n");
                //      command("say ������Ƥ�����ˣ���������ˡ�\n");
                return 1;
                }       
        } 
        else {
                message_vision("$Nɨ��һ��$n���еĶ���˵�������ֶ�����ʲô�á���\n",this_object(),this_player());
                return 0;
                }
} 
