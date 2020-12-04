#include <ansi.h> 
#include <armor.h>

inherit WAIST;

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
	      set_name("[1;36m����֮����[2;37;0m", ({ "sanqing waist", "waist" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[1;36m����������������Σ������컯��һ�����壡����ǡ�����һ����塣��
[2;37;0m����һ���ɼ����Ӳ��[31m��������[2;37;0m����[1;37m����˿[2;37;0m�Ƴɣ�������һ����Ǯ��[1;36m����֮����[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m �����������̣�����[34m����[2;37;0m�ķ�������
������˼����ŷ��ţ�
[1;33m��[2;37;0m:[1;31m��Ԫ[2;37;0m [36mľ[2;37;0m:[31m����[2;37;0m [33m��[2;37;0m:[1;31m��˫[2;37;0m [1;37m��[2;37;0m:[1;34m����[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;31m����[2;37;0m ����:[33m�ܸ�[2;37;0m 
��ʯ:[32m�ֲ�[2;37;0m ��ʯ:[34mϸ��[2;37;0m ����:[1;36m����[2;37;0m ����:[32m�ֲ�[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m����[2;37;0m ������һЩ�� [1;32m����[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "fend");
		set("ownername", "����");
		set("value", 25000);
		set("armor_prop/intelligence",48);
		set("armor_prop/strength",40);
		set("armor_prop/karey",56);
		set("armor_prop/percao",48);
		set("armor_prop/dexerity",48);
		set("armor_prop/constitution",48);
    set("armor_prop/dodge", 35);
    set("armor_prop/parry", 26);
    set("armor_prop/attack", 56);


    set("armor_prop/armor", 469);
    set("armor_prop/defense", 48);
    
    set("armor_prop/neili", 70);
    set("armor_prop/qi", 33);
    set("armor_prop/jing", 48);
    set("armor_prop/jingli", 56);
    set("armor_prop/damage", 244);

    set("wtypeA",13);
    set("wtypeB",6);
    set("wtypeC",5);
    set("wtypeD",4);
    set("wtypeE",12);
    set("wtypeF",7);
    set("wtypeG",8);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",12);
    set("wtypeK",5);
    set("wtypeL",6);
    
    
                set("skill", ([
                        "name": "axe",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 15);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";