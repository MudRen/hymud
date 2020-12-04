#include <ansi.h> 
#include <armor.h>

inherit HANDS;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[1;37mɱ������[2;37;0m", ({ "joeywus hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[1;34m������������ͳ�ε�ʱ��������ӵĽ�Ҳ��ֵ��ͷĸţ�ļ�Ǯ�����������Լ����ǰѴ���ʽ
�������������˹����˵�ǰ��˰���ġ�Τ�����������죬�˵����������
[2;37;0m����һ�����ޱȼ�Ӳ��[37m����[2;37;0m����[1;33m�����˿[2;37;0m�Ƴɣ�����������Ǯ��[1;34m������˹֮����[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m �������ޱȼ�̣�����[32mˮ׼����[2;37;0m�ķ�������
������˼����ŷ��ţ�
[1;33m��[2;37;0m:[35m��׼[2;37;0m [32mˮ[2;37;0m:[1;31m����[2;37;0m [33m��[2;37;0m:[1;35m����[2;37;0m [1;35m��[2;37;0m:[1;36m����[2;37;0m 
[1;37m��[2;37;0m:[1;31m��Ԫ[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;33m����[2;37;0m ����:[34mϸ��[2;37;0m ����:[32m�ֲ�[2;37;0m 
����:[33m�ܸ�[2;37;0m ��ʯ:[1;36m����[2;37;0m ��ʯ:[32m�ֲ�[2;37;0m ����:[34mϸ��[2;37;0m ����:[32m�ֲ�[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m��ҩʦ[2;37;0m ������һЩ�� [1;32m����[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "yellow");
		set("ownername", "��ҩʦ");
		set("value", 25000);
		set("armor_prop/intelligence",56);
		set("armor_prop/strength",56);
		set("armor_prop/karey",56);
		set("armor_prop/percao",56);
		set("armor_prop/dexerity",56);
		set("armor_prop/constitution",56);
    set("armor_prop/dodge", 72);
    set("armor_prop/parry", 48);
    set("armor_prop/attack", 56);


    set("armor_prop/armor", 3333);
    set("armor_prop/defense", 56);
    
    set("armor_prop/neili", 56);
    set("armor_prop/qi", 56);
    set("armor_prop/jing", 48);
    set("armor_prop/jingli", 56);
    set("armor_prop/damage", 4127);

    set("wtypeA",6);
    set("wtypeB",0);
    set("wtypeC",14);
    set("wtypeD",7);
    set("wtypeE",11);
    set("wtypeF",7);
    set("wtypeG",13);
    set("wtypeH",6);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",6);
    set("wtypeL",7);
    
    
                set("skill", ([
                        "name": "club",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 16);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";