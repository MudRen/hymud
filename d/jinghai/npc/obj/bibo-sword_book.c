inherit ITEM;

void create()
{
       set_name("�̲�����Ҫ��", ({ "swordbook"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
        set("unit", "��");
        set("long",
"�Ȿ������ֻ��һЩ�ּ�ģ�����־䣬�ƺ�\n"
"д����һЩȭ����ľ���̸֮ʲô�á�\n");
        set("value", 800);
        set("material", "paper");
        set("skill", ([
        "name":         "sword", // �书����
        "exp_required": 5000,    // ��������Ҫ����;���.
        "jing_cost":     55,      // ���黨����.
        "difficulty":   25,      // �ο� /cmds/std/study.c
        "max_skill":    190,      // �ܶ�������ߵȼ�.
]) );
        }
}
int is_jinghai_book() { return 1; }

