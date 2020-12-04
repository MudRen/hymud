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
	      set_name("[1;36mÇàÁúÖ®ÊÖÌ×[2;37;0m", ({ "qinglong hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¸±");
		set("long", @LONG
[1;36mÇàÁúÖ®ÊÖÌ×[2;37;0mÕâÊÇÒ»¸±ÓÉ¼«Îª¼áÓ²µÄ[1;33m½ğÌú[2;37;0m¼ÓÉÏ[1;33mÄ¾ÃŞ»¨[2;37;0mÖÆ³É£¬ÖØÎå½ï¾ÅÁ½°ËÇ®µÄ[1;36mÇàÁúÖ®ÊÖÌ×[2;37;0m¡£
×ÛºÏÆÀ¼Û[37m¾øÊÀÎŞË«[2;37;0m ¿´ÆğÀ´¼«Îª¼á¹Ì£¬¾ßÓĞ[36m²»Ğ¡[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[37mÌì[2;37;0m:[1;35m¾øÊÀ[2;37;0m [36mÄ¾[2;37;0m:[31m¾«ÖÂ[2;37;0m [31m»ğ[2;37;0m:[1;35m¾øÊÀ[2;37;0m [33mÍÁ[2;37;0m:[35m±ê×¼[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;31mÎŞË«[2;37;0m ÇÉÖÆ:[32m´Ö²Ú[2;37;0m 
°×Ê¯:[33mºÜ¸ß[2;37;0m ³¤Éú:[36m²»´í[2;37;0m ²»ÀÏ:[32m´Ö²Ú[2;37;0m ÍşÁ¦:[34mÏ¸Ëé[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÑ©¶ù[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m±Ş·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "bmr");
		set("ownername", "Ñ©¶ù");
		set("value", 16000);
		set("armor_prop/intelligence",56);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",48);
		set("armor_prop/constitution",48);
    set("armor_prop/dodge", 44);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 744);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 17);
    set("armor_prop/jing", 34);
    set("armor_prop/jingli", 34);
    set("armor_prop/damage", 971);

    set("wtypeA",0);
    set("wtypeB",6);
    set("wtypeC",0);
    set("wtypeD",11);
    set("wtypeE",5);
    set("wtypeF",5);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",11);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",7);
    
    
                set("skill", ([
                        "name": "whip",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		


		set("material", "default");
    set("sharpness", 18);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";