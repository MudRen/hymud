//Cracked by Roath

#include <ansi.h>
inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
          set_name("����", ({"ao guang", "ao","guang","longwang","wang"}));

   set("long","�����Ƕ��������������ֱֵܷ��ƹܶ��������ϣ����ĺ���
������ˮ���ڶ࣬���ƺƴ�ٲȻ����һ����\n");
          set("gender", "����");
          set("age", 66);
   set("title", "��������");
   set("class","dragon");
          set("attitude", "aggressive");
          set("shen_type", 1);
        set("combat_exp", 1260000);
        set("rank_info/respect", "����");
          set("per", 20);
          set("str", 30);
          set("max_qi", 3000);
          set("max_jing", 400);
          set("max_jing", 800);
          set("neili", 3000);
          set("max_neili", 1500);
          set("force_factor", 120);
          set("max_neili", 800);
          set("neili", 1600);
          set("mana_factor", 40);
          set("combat_exp", 1200000);
          set_skill("unarmed", 200);
          set_skill("dodge", 180);
          set_skill("force", 180);
          set_skill("parry", 180);
          set_skill("hammer", 190);
          set_skill("staff", 180);
          set_skill("spells", 150);
    

          create_family("��������", 1, "ˮ��");
          set_temp("apply/armor",150);
          set_temp("apply/damage",125);
          setup();
initlvl((200+random(100)),6);
        carry_object("/d/obj/cloth/longpao")->wear();
}


void init()
{
     object ob = this_player();
     string env;
     env=environment()->query("short");
     if( env == "[1;33m����̨[m"&& ob->query("fish") ) 
     message("channel:chat",HIC+"�����㡿�������̵�"+ ob->query("name") +"������˭�ٸҵ��㣬������Ӳ�������\n"+NOR,users());

}
