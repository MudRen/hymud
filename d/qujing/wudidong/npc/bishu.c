// bishu.c ����
// 9-2-97 pickle

#include <ansi.h>
inherit NPC;
#include "/d/migong/romnpc2.c"

/************************************************************/

// function and global variable declaractions

int attempt_apprentice(object me);
int recruit_apprentice(object me);
int prevent_learn(object me, string skill);
int accept_object(object me, object ob);
void bishu_leave(object me);
/************************************************************/

void create()
{
  set_name("����", ({"bi shu", "bi", "shu", "bishu", "monster"}));
  set("gender", "Ů��");
  set("age", 19);
  set("long",
"��Ȼ���������������磬����˵���츳���ѣ��ǿ����ɵĺ����ӡ�\n"
"�Դ����޵׶������������书�������죬���иϹ�����ļ�ʽ��\n");
  set("title", "�޵׶������");
  set("nickname", HIR"����һ��"NOR);
  set("combat_exp", 800000);
  set("combat_exp", 441500000);

  set("attitude", "heroic");
  create_family("�ݿ�ɽ�޵׶�", 2, "����");
  set_skill("unarmed", 100);
  set_skill("dodge", 100);
  set_skill("parry", 100);

  
  set("cor", 50);
  set("str", 30);
  set("per", 30);
  set("max_qi", 900);
  set("max_jing", 900);
  set("neili", 650);
  set("max_neili", 650);
  set("force_factor", 20);
  set("neili", 650);
  set("max_neili", 600);
  set("mana_factor", 25);
  set("inquiry", ([
                   "name": "��������ǵ�ӿ���˵Ŀ�ɽ����ӣ�",
                   "here": "��Ϲ��������������Ƕ����������ݿ�ɽ�޵׶���",
		   "rumors": "��֪�����ұ�����ȥ��",
		   "�������": "��Ϲ���������������ֲ��ǳ��ӣ�",
                 ]) );  

  setup();
  initlvl((650+random(650)),28);  
  carry_object("/d/obj/weapon/blade/blade")->wield();
  carry_object("/d/obj/cloth/nichang")->wear();
}


/************************************************************/

int accept_object(object me, object ob)
{
    if (ob->query("name_recognized") != "�׹���")
	return notify_fail(CYN"����ŭ�������ʣ����ֲ��������õģ�\n"NOR);
    remove_call_out("bishu_leave");
    call_out("bishu_leave", 1, me);
    return 1;
}
void bishu_leave(object me)
{
    command("say �⡢�⡢�⣬�����ô���Ǻã�");
    command("sigh");
    command("say ��Ȼ���������ڴˣ��һ��ǸϽ���ȥһ�˰ɣ�");
    message_vision("����ץ��һ�����������һ�ף��������ߣ�������ȥ�ˡ�\n", me);
    destruct(this_object());
    return;
}

