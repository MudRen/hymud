#include <ansi.h>
inherit NPC;
void goto_batdao(object ob);
void create()
{
    set_name("����", ({ "ding feng", "ding", "feng" }));
    set("long", "
��������������ƮƮ�������������������Ҳ���ú�Ӣ����
���ϸ���Զ������Ц�ݡ�\n" );
 set("nickname", HIC "�����ٷ�" NOR);
 set("gender", "����");
 set("age", 27);
 set("int", 24);
 set("con", 25);
 set("no_arrest",1); 
 set("neili", 500);
 set("max_neili", 500);
 set("force_factor", 50);
 set("combat_exp", 800000);
 set("attitude", "friendly");  
 set("chat_chance", 1);
 set("chat_msg", ({
"�����૵�����ɽ����һ�ס����ʮ��ʽ����ȷ�����������������ܼ���
�����صġ��������ʽ�����������硣\n ",
"����΢Ц���������ʮ��ʽ��������ڡ��嵭������,���������ǣ��������ޣ�
��ʵ���飬�Ʊ�δ�� ��\n",
 }) );
 set("inquiry",([
  "���ʮ��ʽ" : "�����˻�ɽ��ɽ֮��������ȴʧ���ˣ�����\n",
 ]) );
        set_skill("unarmed", 70);
        set_skill("dodge", 100);
        set_skill("dodge", 100);
        set_skill("parry", 90);
        set_skill("force", 90);
        set_skill("sword", 90);
        set_skill("lonely-sword", 340);
        set_skill("zixia-shengong", 390);

        map_skill("force", "zixia-shengong");
        map_skill("parry", "lonely-sword");
        map_skill("sword", "lonely-sword");

        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield(); 
}   
void init() 
{ 
     ::init(); 
    if( !query_heart_beat(this_object()) ) set_heart_beat(1); 
}   
int accept_object(object who, object ob)
{
    object room;
    if((string) ob->query("id") == "qing feng book")
    {
 //       remove_call_out("verygood_job");
        call_out("verygood_job",2, who);
        return 1;
    }
    else message_vision("�����$N˵�������������ûʲô��ϵ��\n", who);
    return 0;
} 
int verygood_job(object who)
{
  object room;
  if(!objectp(who)) return 1;
  if (who->is_ghost()) return 1;
  command("smile");
  command("say �ã���������������Ҫ�ҵ����ˣ����ϴ������¹������ȥ��\n");
  tell_object(who, GRN "���ϲ��������������������˴󺣴�.......\n\n" NOR ) ;
  message_vision("����һ�������ϴ���æ����һ��������ඣ�\n", who);
  message_vision("�������𷫣������򶫷����С�\n\n", who);
  room = load_object("/d/tieflag/bat/dahai");
  who->move(room);
//destruct(this_object());
  return 1 ;
}       
