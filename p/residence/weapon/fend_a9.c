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
	      set_name("[1;36mÈıÇåÖ®Ñü´ø[2;37;0m", ({ "sanqing waist", "waist" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ìõ");
		set("long", @LONG
[1;36m´óµÀÎŞÃû£¬¾ÛÆø³ÉĞÎ£¬¹¦²ÎÔì»¯£¬Ò»ÊÇÈıÇå£¡Õâ±ãÊÇ¡°ÀÏ×ÓÒ»î¸»¯ÈıÇå¡£¡±
[2;37;0mÕâÊÇÒ»ÌõÓÉ¼«Æä¼áÓ²µÄ[31mÍòÄêÉñÌú[2;37;0m¼ÓÉÏ[1;37m±ù²ÏË¿[2;37;0mÖÆ³É£¬ÖØÈı½ïÒ»Á½ÈıÇ®µÄ[1;36mÈıÇåÖ®Ñü´ø[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´¼«Æä¼á¹Ì£¬¾ßÓĞ[34m²»´í[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[1;31m¿ªÔª[2;37;0m [36mÄ¾[2;37;0m:[31m¾«ÖÂ[2;37;0m [33mÍÁ[2;37;0m:[1;31mÎŞË«[2;37;0m [1;37mÀ×[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;31m»ÙÌì[2;37;0m ÇÉÖÆ:[33mºÜ¸ß[2;37;0m 
°×Ê¯:[32m´Ö²Ú[2;37;0m ×ÏÊ¯:[34mÏ¸Ëé[2;37;0m ÖÜÌì:[1;36mÍêÃÀ[2;37;0m ³¤Éú:[32m´Ö²Ú[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m·½·½[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m¸«·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

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
		set("ownername", "·½·½");
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