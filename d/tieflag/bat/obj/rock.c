 inherit ITEM;
#include <ansi.h>
void create()
{
    set_name("��ʯ", ({ "rock" , "��ʯ","ŭ��"}) );
        set_weight(500);
        set_max_encumbrance(8000);
        set("no_get", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long", "һ������ǧ���ɣ�Ľ�ʯ�����澹����������������������д��֣�
\n\n"+HIC"                ƮƮ������\n\n"NOR+HIY"                     ���һɳŸ\n\n"NOR+"
    ���������������������Ȼ��ʮ�����״���ͽ��������ڳ������
    ��ͽ�³ǣ�������ţ�������֮�����򽣵�������Ȼһ����ͼ���������ģ�
�γ��ڽ����������ӣ����ǽⲻ��һ��������Ե���غ����գ���Ե�ɵ���������
֮��������Ե���������ӳ��ᣡ����֮�ˣ����޺��ӣ�\n");
                set("value", 1);
            set("skill", ([
                        "name":         "sword",        
                        "exp_required": 0,              
                        "jing_cost":     90,     
                        "difficulty":   10,     
                        "max_skill":    100              
                ]) );

        }
        
} 
int is_container() { return 1; }       
