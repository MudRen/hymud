//Cracked by Roath
// by happ@ys

#include <ansi.h>

inherit NPC;
#include "/d/migong/romnpc2.c"

int send_me();
int work_me();
string expell_me(object me);
string check_book();
int zhua_gui();
string ask_cancel();
string obstacle_sc();

void create()
{
       set_name("������", ({"yanluo wang","wang", "master", "yanluo"}));
       set("long", "��������ۣ�ͷ���ڳ����
������ף��������룬�������������\n");
       set("title", "����ʮ��֮");
        set("class", "youling");
       set("gender", "����");
       set("age", 50);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("per", 10);
      

set("inquiry", ([
"name": "�ߣ����Ϸ򶼲��ϵã������ǻ��̫���ˣ�\n",
"here": "��������޵ظ���������һ̸���ٺ٣�û�˲��£�\n",
"����": "��˵������;����ʵ��Ȼ��������������ཻ����ȥ��ͨ��\n",
"���": "������Ҫ˵֪������ȴҲ���࣬�Ǳ����꣬�£��գ�ʱ�ͳ�����ˮ�ţ�\n",
"����": (: obstacle_sc :),
"�����յĸ���": (: obstacle_sc :),

]) );


create_family("���޵ظ�", 2, "���");
setup();
initlvl((500+random(500)),3);
        carry_object("/d/obj/cloth/mangpao")->wear();
        carry_object("/d/obj/weapon/sword/qinghong")->wield();
}
string obstacle_sc()
{
        object me = this_player();
        int i;
        if( me->query("obstacle/sc") == "done" )
        return("�Ҳ�̫�����\n");
  if (me->query("combat_exp",1) < 1000000)
    return("�Ҳ�̫�����\n");            
        if( ! me->query_temp("can_ask") )
          return("�Ҳ�̫�����\n");

  i = random(800)+100;
  me->add("obstacle/number",1);
  me->set("obstacle/sc","done");
    me->add("combat_exp",i+7000);
    me->add("potential",i*8);
    me->add("mpgx",10);me->add("expmax",2);
  command("chat "+me->query("name")+"˫�����𻢣�������������Թ��ͣ�");
message("channel:chat",HIY"������ն������������(guanyin pusa)��"+me->query("name")+"��������ȡ��[1;37m�ڶ��أ�\n"NOR,users());
  me->save();
me->move("/d/qujing/shuangcha/sleeproom");

  return("��Ӯ����"+chinese_number(i+7000)+"�㾭��"+
               chinese_number(i*8)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");

}

