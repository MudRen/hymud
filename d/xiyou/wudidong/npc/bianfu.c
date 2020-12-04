// bianfu.c ���� 
// 9-18-97 pickle 
 
#include <ansi.h> 
inherit NPC; 
#include "/d/migong/romnpc2.c"
 
/************************************************************/ 
 
// function and global variable declaractions 
 
int attempt_apprentice(object me); 
int recruit_apprentice(object me); 
void transform(); 
string ask_me(); 
void transform_back(); 
void mie_kou(object me); 
 
/************************************************************/ 
 
void create() 
{ 
 
  set_name("�", ({"qiong han", "qiong", "han", "poor man","man"})); 
  set("title", "��ͨ����"); 
  set("long", 
"��������һ�������ʵ������ӣ�����ûһ���������·����ݹ���᾵ģ�\n" 
"��������û�Թ�һ�ٱ����Ƶġ���˵���������������˱ȱȽ��ǣ�����\n" 
"�������Ǿ��ò�˳�ۡ���ϸ����һ�����㷢��ԭ����ȫ����һ�㵭��\n" 
"����ë��\n"); 
  set("combat_exp", 3000); 
  set("combat_exp", 500000); 
 
  set("attitude", "peaceful"); 
  set("gender", "����"); 
  set("age", 39); 
  create_family("�ݿ�ɽ�޵׶�", 2, "����"); 
 
  set_skill("unarmed", 80); 
  set_skill("dodge", 80); 

 
  set("str", 20); 
  set("cor", 100); 
  set("int", 20); 
  set("spi", 30); 
  set("cps", 100); 
  set("per", 10); 
  set("con", 40); 
  set("kar", 20); 
   
  set("env/wimpy", 70); 
 
  set("max_qi", 400); 
  set("max_jing", 400); 
  set("neili", 350); 
  set("max_neili", 350); 
  set("neili", 350); 
  set("max_neili", 300); 
  set("inquiry", ([ 
                   "name": "�����������������ֶ�������ʲô���ˣ�", 
                   "here": "�������������˭ȥ��", 
                   "rumors": "��˵���������Щ�����ڳ����ǳ�û������", 
                   "����": "����˵�����Ǹ�ʲôʲôɽʲôʲô���ģ�Ҳ��֪զ���¡�", 
                   "�ݿ�ɽ": (: ask_me :), 
                   "�޵׶�": (: ask_me :), 
                 ]) );   
 
  setup(); 
initlvl((550+random(550)),29);  
  carry_object("/d/obj/cloth/pobuyi")->wear(); 
} 
/************************************************************/ 
 
// the menpai settings, but only useful after npc transforms. 
 

void transform() 
{ 
  object weapon; 
  if(!interactive()) 
    return; 
  set_name("����", ({"bian fu", "bianfu", "fu", "bat", "monster"})); 
  set("title", "����"); 
  set("long", 
"��������һֻ�޴�����𣬵���֪Ϊ�ξ�Ȼ��˵�˻���\n"); 
  set("combat_exp", 300000); 
  set("combat_exp", 33500000); 
 

  set("wudidong_state", 1); 
  message_vision(HIY"�ҡ��һ�䣬����ԭ�Ρ�ԭ����ֻ����\n"NOR, this_object()); 
} 
void mie_kou(object me) 
{ 
    string myid=me->query("id"); 
    if (!interactive()) return; 
    if (me->query("family/family_name") == "�ݿ�ɽ�޵׶�") 
    { 
        command("pat "+myid);                   // if he has bai in meantime 
        command("say ����ʶʱ���߿��ܣ�");    // don't kill him, compliment him 
        call_out("transform_back", 300);        // change back to human 
        return; 
    } 
    if (!present(myid, environment())) 
    { 
        command("sneer");                       // laugh at the cowards 
        command("say �ҿ�"+me->name()+"��ÿ졣���򣬺ߣ��ߣ��ߣ�"); 
        call_out("transform_back", 300); 
        return; 
    } 
    if (!query("wudidong_state"))               // if still in human form 
        transform();                            // change into bianfu form to kill 
    command("say "+me->name()+"�����Ȼִ�Բ����Ǿ��������ɣ�"); 
    command("kill "+myid);                      // kill! 
    call_out("transform_back", 180);            // assume fight over in 3 min 
    return;                                     // at which time change back 
} 
void transform_back() 
{ 
    object weapon, me=this_object(); 
 
    if(!query("wudidong_state"))                // if already in human form, no point. 
        return; 
    if(!interactive())                          // can't change back if fainted 
    {                                           // give another 30 sec 
        remove_call_out("transform_back"); 
        call_out("transform_back", 30); 
        return; 
    } 
    if (is_fighting())                          // obviously can't change back 
    {                                           // if still fighting, so give 
        remove_call_out("transform_back");      // it another 3 min 
        call_out("transform_back", 180); 
        return; 
    } 
  if (objectp(weapon=present("sword", me))) 
    destruct(weapon); 
  message_vision(HIY"$Nҡ��һ�䣬����˸����\n"NOR, this_object()); 
  set_name("�", ({"qiong han", "qiong", "han", "poor man","man"})); 
  set("title", "��ͨ����"); 
  set("long", 
"��������һ�������ʵ������ӣ�����ûһ���������·����ݹ���᾵ģ�\n" 
"��������û�Թ�һ�ٱ����Ƶġ���˵���������������˱ȱȽ��ǣ�����\n" 
"�������Ǿ��ò�˳�ۡ���ϸ����һ�����㷢��ԭ����ȫ����һ�㵭��\n" 
"����ë��\n"); 
  set("combat_exp", 3000); 
  set("combat_exp", 33500000); 
 

  return; 
} 


