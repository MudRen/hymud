 // teacher.c
inherit NPC; 
void create()
{
        set_name("���ʵ�", ({ "kaoguan", "kao" }) );
        set("title", "���⿼��");
        set("gender", "����" );
        set("age", 47);
        set("int", 26);
        set("skill_public",1);
        set("long",
                "���ʵ��Ǹ���ѧ���ŵ����⿼�٣�������ʱ�����й����ˣ�����\n"
                "��Ϊ����ϲ�������˲�Ը���٣����ʵ��Լ࿼Ϊҵ�������Ըѧ\n"
                "���ʵ����ǻ�̵ģ�\n");
        set("attitude", "peaceful");
        set_skill("literate", 120);
        setup();
} 
int recognize_apprentice(object ob)
{
        return 1;
}  
