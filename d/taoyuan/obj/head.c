 //TIE@FY3
inherit ITEM;
void create()
{
    set_name("ͷ­��", ({ "skull"}) );
    set_weight(500);
    set_max_encumbrance(1000);
    set("no_get", 1);
    set("no_shown", 1);
        set("skull",1);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "һ���븯�õ�ͷ­�ǣ�ɢ����һ�ɶ�����ӽ����Ƥ���ϣ���
��ϡ�������䵱�������ţ�ͷ�ǰٻ�Ѩ�ĵط�����һ���ߴ糤��������������
ͷ����ȫ���������ڣ��������ͷ­�ǵ��۾��Ѿ��õ������û������������
������\n");
        set("value", 1);
    }
    
} 
int is_container() { return 1; }        
