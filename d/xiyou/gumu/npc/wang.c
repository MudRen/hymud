//��ԯ��ĹNPC ������

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

string say_key();
void punish_player(object me);
int accept_object(object me, object ob);

/************************************************************/
void create()
{
  set_name(HIW"������" NOR, ({"wang guiren", "wang", "guiren"}));
    set_weight(1000000);
  set("gender", "Ů��" );
  set("age", 23);
   set("long", "
��槼�һͬ������ɽ������һֻʯ���þ���������ǳ��ȴ����ס������
���ʮɫ����˷��������������ջ󣬶���ħ�������ڳ��豻����ռ��
��ʿ��̫������������һ�Ǵ���������˷���̨������槼�һͬ����
\n");
  set("title", HIB"��ʯ���þ�" NOR);
  set("combat_exp", 10000000);
  set("attitude", "heroic");
  create_family("��ԯ��Ĺ", 1, "����");
  set("int", 25+random(5));
  set("cor", 30+random(10));
  set("per", 40);
  set_skill("unarmed", 220);
  set_skill("dodge", 220);
 
  set("per", 50);
  set("max_kee", 5000);
  set("max_sen", 5000);
  set("force", 6000);
  set("max_force", 3000);
  set("force_factor", 150);
  set("mana",6000);
  set("max_mana", 3000);
  set("mana_factor", 150);
  set("inquiry",([
       "name": "�Ҿ����������ˣ���Ҫ���ң�",
       "here": "���������ԯ��Ĺ������ʯ�����������Ұ���ߣ����ֲ����㣡",
       ]));
  set("chat_chance_combat", 60);
   
   set("chat_msg_combat", ({
    (: perform_action, "sword.hebi" :)
   }) );
  setup();
  carry_object("/d/obj/weapon/sword/xy_sword.c")->wield();
  carry_object("/d/obj/cloth/nichang")->wear();
  carry_object("/d/obj/cloth/yuanxiang")->wear();
}
