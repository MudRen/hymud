#include <ansi.h> 
#include <armor.h>

inherit WRISTS;

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
	      set_name("[1;31m��ҩ֮����[2;37;0m", ({ "general wrists", "wrists" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
		set("long", @LONG
��ҩ֮����[2;37;0m����һ˫��ʮ�ּ�Ӳ��[33m����[2;37;0m����[33m����[2;37;0m�Ƴɣ���һ�������Ǯ��[1;31m��ҩ֮����[2;37;0m��
�ۺ�����[31m��������[2;37;0m ������ʮ�ּ�̣�����[36mһ��[2;37;0m�ķ�������
������˼����ŷ��ţ�
[33m��[2;37;0m:[35m��׼[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[33m�ܸ�[2;37;0m ����:[36m����[2;37;0m ����:[34mϸ��[2;37;0m 

�Լ�һ�Ź�׭�֡� [1;32mҹҹҹ[2;37;0m ������һЩ�� [1;32m�޷�[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "yyy");
		set("ownername", "ҹҹҹ");
		set("value", 2000);
		set("armor_prop/intelligence",13);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 31);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",5);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "whip",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 120,              
                ]) );		


		set("material", "default");
    set("sharpness", 4);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";