inherit ITEM;

void create()
{
        set_name("���Ѳ����ؼ�", ({ "dodgebook" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
        set("unit", "��");
        set("long",
"�Ȿ���ֽ�Ŷ��Ѿ������ˣ�����ֻ��һЩ�ּ�ģ�����־䣬�ƺ�\n"
"д������Ů֮���һЩ�黰ʲô�á�\n");
        set("value", 800);
        set("material", "paper");
        set("skill", ([
        "name":         "dodge", // �书����
        "exp_required": 1000,    // ��������Ҫ����;���.
        "jing_cost":     50,      // ���黨����.
        "difficulty":   25,      // �ο� /cmds/std/study.c
        "max_skill":    181,      // �ܶ�������ߵȼ�.
]) );
        }
}
int is_jinghai_book() { return 1; }

