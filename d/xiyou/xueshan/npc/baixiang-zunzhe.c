
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// baixiang-zunzhe.c...weiqi, 97.09.15.

inherit NPC;
string ask_chuxian();
   string ask_cancel();
void create()
{
   set_name("��������", ({"baixiang zunzhe", "baixiang", "zunzhe"}));
   set("title", "��������");
   set("gender", "����" );
   set("age", 43);
   set("per", 112);//no rongmao description.
   set("str", 50);
   set("long", "��λ���������������Ĵ���ʿ����ǰ��ʨ��ɽ����������\nʨ��ɽ���������������ʨ��ħͶ���������������˻������ߡ�\n��ƽ���µ������󣬿�������������˾����ᡣ\n");
   set("class", "yaomo");
   set("combat_exp", 800000);
   set("attitude", "peaceful");
   create_family("��ѩɽ", 2, "����");
 

   set("max_kee", 1200);
   set("max_sen", 600);
   set("force", 1600);
   set("max_force", 800);
   set("mana", 800);
   set("max_mana", 400);   
   set("force_factor", 60);
   set("mana_factor", 20);

        set("eff_dx", -200000);
        set("nkgain", 400);

   setup();
   carry_object("/d/obj/armor/yinjia")->wear();
   carry_object("/d/obj/weapon/blade/yanblade")->wield();
}
