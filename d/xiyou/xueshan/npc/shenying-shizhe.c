// sgzl, 99.0.15.
// �������ֺ�����ĺ���������

inherit NPC;

int test_hispai(object ob);
void give_yaopai(object ob);
string give_map(object me);
int do_yes(string arg);

void create()
  {
   set_name("��ӥʹ��", ({"shenying shizhe", "shizhe", "shenying", "eagle"}));
   set("gender", "����" );
   set("age", 34);

   set("long", "��ѩɽѲɽ�ܶ�������ӥʹ�ߣ������Ĵ�Ѳ�飬�˷����硣\n");
   set("class", "yaomo");
   set("combat_exp", 80000);
   set("daoxing", 75000);

   set("attitude", "heroism");
   create_family("��ѩɽ", 3, "����");
   set_skill("unarmed", 60);
  
   set("max_kee", 500);
   set("max_sen", 500);
   set("force", 700);
   set("max_force", 700);
   set("mana", 700);
   set("max_mana", 700);	
   set("force_factor", 35);
   set("mana_factor", 35);


   set("inquiry", ([
	"name" : "���´�ѩɽ��ӥʹ�ߣ��кι�ɣ�\n",
	"here" : "�����أ������Ȳ������Ǵ�ѩɽ��\n",

	]) );

   set("no_map", 0);

   setup();

   carry_object("/d/obj/cloth/xueshan-pao")->wear();
   carry_object("/d/obj/armor/tenjia")->wear();

}

