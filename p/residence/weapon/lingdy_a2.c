#include <ansi.h> 
#include <armor.h>

inherit SHIELD;

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
	      set_name("[1;32mÎäÒíÖ®¶Ü[2;37;0m", ({ "wuyi shield", "shield" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ãæ");
		set("long", @LONG
[1;32mÎäÒíÖ®¶Ü[2;37;0mÕâÊÇÒ»ÃæÓÉÎŞ±È¼áÓ²µÄ[1;33m½ğÌú[2;37;0m¼ÓÉÏ[32mÓñ²ÏË¿[2;37;0mÖÆ³É£¬ÖØÊ®Ò»½ïÒ»Á½ÁùÇ®µÄ[1;32mÎäÒíÖ®¶Ü[2;37;0m¡£
×ÛºÏÆÀ¼Û[37m¾øÊÀÎŞË«[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[32mË®×¼ÒÔÉÏ[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[1;32mÄ§Íõ[2;37;0m [31m»ğ[2;37;0m:[1;32mÄ§Íõ[2;37;0m [1;35m·ç[2;37;0m:[1;32mÄ§Íõ[2;37;0m 
[1;37mÀ×[2;37;0m:[33mºÜ¸ß[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;31mÎŞË«[2;37;0m ÇÉÖÆ:[32m´Ö²Ú[2;37;0m 
°×Ê¯:[33mºÜ¸ß[2;37;0m ×ÏÊ¯:[32m´Ö²Ú[2;37;0m ÖÜÌì:[35m±ê×¼[2;37;0m ³¤Éú:[32m´Ö²Ú[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m·ç·ç[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÄÚ¹¦[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "lingdy");
		set("ownername", "·ç·ç");
		set("value", 16000);
		set("armor_prop/intelligence",48);
		set("armor_prop/strength",40);
		set("armor_prop/karey",48);
		set("armor_prop/percao",32);
		set("armor_prop/dexerity",32);
		set("armor_prop/constitution",48);
    set("armor_prop/dodge", 41);
    set("armor_prop/parry", 32);
    set("armor_prop/attack", 48);


    set("armor_prop/armor", 575);
    set("armor_prop/defense", 40);
    
    set("armor_prop/neili", 54);
    set("armor_prop/qi", 36);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 40);
    set("armor_prop/damage", 296);

    set("wtypeA",9);
    set("wtypeB",6);
    set("wtypeC",5);
    set("wtypeD",9);
    set("wtypeE",5);
    set("wtypeF",9);
    set("wtypeG",4);
    set("wtypeH",0);
    set("wtypeI",5);
    set("wtypeJ",4);
    set("wtypeK",4);
    set("wtypeL",5);
    
    
                set("skill", ([
                        "name": "force",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		


		set("material", "default");
    set("sharpness", 12);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";