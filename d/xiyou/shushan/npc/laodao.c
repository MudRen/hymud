//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
#include <ansi.h>
inherit NPC;

#define SYNTAX "ָ���ʽ��tellme [player_id] make <id>\n"

int check_ratio(object me, object ob);
int check_base_reward(object ob, int ratio);
int accept_object(object me, object ob);
void move_ob(object ob);
void destroy(object ob);

/************************************************************/

void create()
{
  set_name("���ϵ�", ({"guai laodao", "laodao","daoshi"}));
  set("long",
"���ǽ�ʥ�ľ˾ˣ��뵱�������𽭺�����š��˰����ֻҪ�����֣�\n"
"��Բ�˰����ڣ�û�����������棬����������ʹ��ˣ����Ͳ��ȵ��ꡣ\n"
"����ʥ���������ػ���¯����Ϊ���ͽ�ʥһ������ħ�������������� ��\n");
  set("title", HIY"��ʦ"NOR);
  set("gender", "����");
  set("per", 10);
  set("age", 100);
  set("str", 30);
  set("int", 30);
    set("max_sen", 2000);
  set("max_kee", 2000);
    set("force", 3000);
  set("max_force", 2000);
      set("mana", 3000);
  set("max_mana", 2000);
  
     
   set("attitude", "peaceful");
  set("combat_exp", 1500000);
  set("daoxing",2000000);
  set("inquiry", ([
     "name": "ʲô���֣����Լ������ǵ��ˣ�",
     "here": "����������¯���㿴��������",
     ]));
  setup();
  carry_object("/d/obj/weapon/sword/changjian")->wield();       
  //carry_object("/d/clone/misc/cloth/linen")->wear();
}
/************************************************************/

